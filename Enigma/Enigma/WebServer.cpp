#include "WebServer.h"

#include <cstring>    // sizeof()
#include <iostream>
#include <string>   

#ifdef WIN32                // Windows 95 and above
#include "winsock2.h"       // Almost everything is contained in one file.
#include "Ws2tcpip.h"

#ifndef socklen_t
typedef int socklen_t;
#endif

#else                       // UNIX/Linux
#include <sys/types.h>      // Header containing all basic data types and typedefs.
#include <sys/socket.h>     // Header containing socket data types and functions.
#include <netinet/in.h>     // IPv4 and IPv6 stuff.
#include <unistd.h>         // For gethostname()
#include <netdb.h>          // For DNS - gethostbyname()
#include <arpa/inet.h>      // Contains all inet_* functions.
#include <errno.h>          // Contains the error functions.
#include <fcntl.h>          // File control.
#endif

#ifndef _UNISTD_H
#define _UNISTD_H    1

/* This is intended as a drop-in replacement for unistd.h on Windows.
 * Please add functionality as neeeded.
 * https://stackoverflow.com/a/826027/1202830
 */

#include <stdlib.h>
#include <io.h>
//#include <getopt.h> /* getopt at: https://gist.github.com/ashelly/7776712 */
#include <process.h> /* for getpid() and the exec..() family */
#include <direct.h> /* for _getcwd() and _chdir() */

#define srandom srand
#define random rand

 /* Values for the second argument to access.
    These may be OR'd together.  */
#define R_OK    4       /* Test for read permission.  */
#define W_OK    2       /* Test for write permission.  */
    //#define   X_OK    1       /* execute permission - unsupported in windows*/
#define F_OK    0       /* Test for existence.  */

#define access _access
#define dup2 _dup2
#define execve _execve
#define ftruncate _chsize
#define unlink _unlink
#define fileno _fileno
#define getcwd _getcwd
#define chdir _chdir
#define isatty _isatty
#define lseek _lseek
/* read, write, and close are NOT being #defined here, because while there are file handle specific versions for Windows, they probably don't work for sockets. You need to look at your app and consider whether to call e.g. closesocket(). */

#ifdef _WIN64
#define ssize_t __int64
#else
#define ssize_t long
#endif

#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2
/* should be in some equivalent to <sys/types.h> */
typedef __int8            int8_t;
typedef __int16           int16_t;
typedef __int32           int32_t;
typedef __int64           int64_t;
typedef unsigned __int8   uint8_t;
typedef unsigned __int16  uint16_t;
typedef unsigned __int32  uint32_t;
typedef unsigned __int64  uint64_t;

#endif /* unistd.h  */


namespace WebHandling {
    WebServer::WebServer() {}

    int WebServer::init(){

        auto& portNum = "8081";
        const unsigned int backLog = 8;  // number of connections allowed on the incoming queue


        addrinfo hints, * res, * p;    // we need 2 pointers, res to hold and p to iterate over
        memset(&hints, 0, sizeof(hints));

        // for more explanation, man socket
        hints.ai_family = AF_UNSPEC;    // don't specify which IP version to use yet
        hints.ai_socktype = SOCK_STREAM;  // SOCK_STREAM refers to TCP, SOCK_DGRAM will be?
        hints.ai_flags = AI_PASSIVE;


        // man getaddrinfo
        int gAddRes = getaddrinfo(NULL, portNum, &hints, &res);
        if (gAddRes != 0) {
            std::cerr << gai_strerror(gAddRes) << "\n";
            return -2;
        }

        std::cout << "Detecting addresses" << std::endl;

        unsigned int numOfAddr = 0;
        char ipStr[INET6_ADDRSTRLEN];    // ipv6 length makes sure both ipv4/6 addresses can be stored in this variable


        // Now since getaddrinfo() has given us a list of addresses
        // we're going to iterate over them and ask user to choose one
        // address for program to bind to
        for (p = res; p != NULL; p = p->ai_next) {
            void* addr;
            std::string ipVer;

            // if address is ipv4 address
            if (p->ai_family == AF_INET) {
                ipVer = "IPv4";
                sockaddr_in* ipv4 = reinterpret_cast<sockaddr_in*>(p->ai_addr);
                addr = &(ipv4->sin_addr);
                ++numOfAddr;
            }

            // if address is ipv6 address
            else {
                ipVer = "IPv6";
                sockaddr_in6* ipv6 = reinterpret_cast<sockaddr_in6*>(p->ai_addr);
                addr = &(ipv6->sin6_addr);
                ++numOfAddr;
            }

            // convert IPv4 and IPv6 addresses from binary to text form
            inet_ntop(p->ai_family, addr, ipStr, sizeof(ipStr));
            std::cout << "(" << numOfAddr << ") " << ipVer << " : " << ipStr
                << std::endl;
        }

        // ask user to choose an address
        std::cout << "Enter the number of host address to bind with: ";
        unsigned int choice = 0;
        bool madeChoice = false;
        do {
            std::cin >> choice;
            if (choice > (numOfAddr + 1) || choice < 1) {
                madeChoice = false;
                std::cout << "Wrong choice, try again!" << std::endl;
            }
            else
                madeChoice = true;
        } while (!madeChoice);

        p = res;

        // let's create a new socket, socketFD is returned as descriptor
        // man socket for more information
        // these calls usually return -1 as result of some error
        int sockFD = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockFD == -1) {
            std::cerr << "Error while creating socket\n";
            freeaddrinfo(res);
            return -4;
        }


        // Let's bind address to our socket we've just created
        int bindR = bind(sockFD, p->ai_addr, p->ai_addrlen);
        if (bindR == -1) {
            std::cerr << "Error while binding socket\n";

            // if some error occurs, make sure to close socket and free resources
            close(sockFD);
            freeaddrinfo(res);
            return -5;
        }


        // finally start listening for connections on our socket
        int listenR = listen(sockFD, backLog);
        if (listenR == -1) {
            std::cerr << "Error while Listening on socket\n";

            // if some error occurs, make sure to close socket and free resources
            close(sockFD);
            freeaddrinfo(res);
            return -6;
        }


        // structure large enough to hold client's address
        sockaddr_storage client_addr;
        socklen_t client_addr_size = sizeof(client_addr);


        const std::string response = "Hello World";


        // a fresh infinite loop to communicate with incoming connections
        // this will take client connections one at a time
        // in further examples, we're going to use fork() call for each client connection
        while (1) {

            // accept call will give us a new socket descriptor
            int newFD
                = accept(sockFD, (sockaddr*)&client_addr, &client_addr_size);
            if (newFD == -1) {
                std::cerr << "Error while Accepting on socket\n";
                continue;
            }

            // send call sends the data you specify as second param and it's length as 3rd param, also returns how many bytes were actually sent
            auto bytes_sent = send(newFD, response.data(), response.length(), 0);
            close(newFD);
        }

        close(sockFD);
        freeaddrinfo(res);

        return 0;
	}
}
// // #include <sys/types.h>
// // #include <iostream>
// // #include <sys/socket.h>
// // #include <arpa/inet.h> 
// // #include <unistd.h>
// // #include <netinet/in.h>
// // #include <netdb.h>
// // #include <stdio.h>
// // #include <string.h>

// // using namespace std;
 
// // int main(int argc,char **argv)
// // {
// //     int sockfd,n;
// //     char sendline[100];
// //     char recvline[100];
// //     struct sockaddr_in servaddr;
 
// //     sockfd=socket(AF_INET,SOCK_STREAM,0);
// //     bzero(&servaddr,sizeof servaddr);
 
// //     servaddr.sin_family=AF_INET;
// //     servaddr.sin_port=htons(12000);
 
// //     inet_pton(AF_INET,"127.0.0.2",&(servaddr.sin_addr));
 
// //     connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
 
// //     while(1)
// //     {
// //         bzero( sendline, 100);
// //         bzero( recvline, 100);
// //         fgets(sendline,100,stdin); /*stdin = 0 , for standard input */
 
// //         write(sockfd,sendline,strlen(sendline)+1);
// //         read(sockfd,recvline,100);
// //         printf("%s",recvline);
// //         // cout << recvline << endl;
// //     }
 
// // }

// //@EDIT

// #include <sys/types.h>
// #include <sys/socket.h>
// #include <netdb.h>
// #include <arpa/inet.h>
// #include <unistd.h>
// #include <stdio.h>
// #include <string.h>

// #define ARRAY_LEN 2
 
// int main(int argc,char **argv)
// {
//     int sockfd,n;

//     int sourceArray[ARRAY_LEN];
//     sourceArray[0] = 1;
//     sourceArray[1] = 2;

//     char sendline[100];
//     char recvline[100];
//     struct sockaddr_in servaddr;
//     int arr[2] = {1, 2};
//     sockfd=socket(AF_INET,SOCK_STREAM,0);
//     bzero(&servaddr,sizeof servaddr);
 
//     servaddr.sin_family=AF_INET;
//     servaddr.sin_port=htons(22000);
 
//     inet_pton(AF_INET,"127.0.0.1",&(servaddr.sin_addr));
 
//     connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
 
//     // while(1)
//     // {
//     //     bzero( sendline, 100);
//     //     bzero( recvline, 100);
//     //     fgets(sendline,100,stdin); /*stdin = 0 , for standard input */
//     //     write(sockfd, arr);
//     //     write(sockfd,sendline,strlen(sendline)+1);
//     //     read(sockfd,recvline,100);
//     //     printf("%s",recvline);
//     // }
//     write(sockfd, sourceArray, sizeof(int) * ARRAY_LEN);
//     printf("sent!!!");
// }

//@EDIT

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <string>

#define ARRAY_LEN 4

using namespace std; 

int main(int argc,char **argv)
{
    int sockfd,n;

    string sourceArray[ARRAY_LEN];
    sourceArray[0] = "1";
    sourceArray[1] = "abc";
    sourceArray[2] = "2";
    sourceArray[3] = "1";

    char sendline[100];
    char recvline[100];
    struct sockaddr_in servaddr;
    int arr[2] = {1, 2};
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    bzero(&servaddr,sizeof servaddr);
 
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(22000);
 
    inet_pton(AF_INET,"127.0.0.1",&(servaddr.sin_addr));
 
    connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
    // printf("one");
    write(sockfd, sourceArray, sizeof(string) * ARRAY_LEN);
    printf("sent!!!");
}
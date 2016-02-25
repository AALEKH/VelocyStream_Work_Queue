//@EDIT

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <string>

#define ARRAY_LEN 2

using namespace std; 

int main(int argc,char **argv)
{
    int sockfd,n;

    string sourceArray[ARRAY_LEN];
    sourceArray[0] = "1";
    sourceArray[1] = "abc";

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
    write(sockfd, sourceArray, sizeof(string) * ARRAY_LEN);
    printf("sent!!!");
}
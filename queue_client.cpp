#include <stdio.h>
#include <map>
#include <string>
#include "iostream"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <arpa/inet.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <velocypack/vpack.h>

using namespace std;
using namespace arangodb::velocypack;

 
int main(int argc,char **argv)
{
    int sockfd, n;
    size_t len;
    map<string,int> ount;
    Builder builder;
    // builder.add("l", Value(ValueType::Array));
    // builder.add(Value("abc"));
    // builder.add(Value("def"));
    // builder.add(Value("ghi"));
    char sendline[100];
    char recvline[100];
    struct sockaddr_in servaddr;
 
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    bzero(&servaddr,sizeof servaddr);
 
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(22000);
 
    inet_pton(AF_INET,"127.0.0.1",&(servaddr.sin_addr));
 
    connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
 
    while(1)
    {
        bzero( sendline, 100);
        fgets(sendline,100,stdin); /*stdin = 0 , for standard input */
        builder.add(string(sendline), Value(ValueType::Array));
        builder.add(Value("abc"));
        builder.add(Value("def"));
        builder.add(Value("ghi"));
        builder.close();
         if(atoi(sendline) ==123){
            // cout << "Yes I  have reached here" << endl;
            printf("Yes I  have reached here");
            write(sockfd, &builder, 100);
            continue;
        }else{
            continue;
        }
        builder.clear();
    }
 
}

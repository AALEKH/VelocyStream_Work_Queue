#include <stdio.h>
#include <map>
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
    // Builder *b;
    map<string,int> ount;
    // ount["12345"] = 5;
    // b.add("12345", Value(5));
    // b->(Value(ValueType::Object));
    // b->add("foo", Value(42)); 
    // b->close();
    // b.close();
    Builder builder;
    builder.isOpenObject();
    builder.add("id", Value(23));
    builder.close();
    //b.add(Value("this is a test"));
    int messageCount[2];
    messageCount[0] = 12345;
    messageCount[1] = 5;
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
    //    bzero( recvline, 100);
        fgets(sendline,100,stdin); /*stdin = 0 , for standard input */
 
        cout << "input text is : " << atoi(sendline) <<"bool: " << (atoi(sendline) == 123)<< endl;
        //write(sockfd,sendline,strlen(sendline));
        if(atoi(sendline) ==123){
        // if((sendline[0] == 'h')&&(sendline[1] == 'o')){
            cout << "Yes I  have reached here" << endl;
            // Slice s(b.start());
            // len = s.byteSize();
            write(sockfd, &builder, 100);
        }else{
            continue;
        }
        //read(sockfd,recvline,100);
        //cout << recvline << endl;
    }
 
}

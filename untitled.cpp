#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#include <velocypack/vpack.h>
#include <iostream>
#include <typeinfo>

#define ARRAY_LEN 2
 
using namespace arangodb::velocypack;
using namespace std;

struct velocystream{
  uint32_t length;
  uint32_t chunkx; // chunkx = chunk + isFirstChunk
  uint64_t messageId;
  uint64_t messageLength;
  arangodb::velocypack::Builder vpacks; // Collection of all Velocypacks
};


int main(int argc,char **argv)
{
    int sockfd,n, count = 0;

    Builder bhj;
	bhj.add(Value("aaa"));
  	ValueLength len;
  	velocystream velocy_one, velocy_two; //srt_l
  	velocy_one.length = 100;
  	velocy_one.chunkx = 12334;
  	velocy_one.messageId = 12345;
  	velocy_one.messageLength = 1;
  	velocy_one.vpacks = bhj;
  	velocy_two.length = 100;
  	velocy_two.chunkx = 12335;
  	velocy_two.messageId = 12346;
  	velocy_two.length = 1;
  	velocy_two.vpacks = bhj;

  	const char *b;

  	const char *c;

  	const char *d;

  	const char *elf;

  	velocystream *srt_l = (velocystream *)malloc(1000);
  
 	char ex[sizeof(velocy_one)];
  	b = static_cast<char*>(static_cast<void*>(&st));
  	c = static_cast<char*>(static_cast<void*>(&velocy_one));
  	d = static_cast<char*>(static_cast<void*>(&velocy_two));

    int sourceArray[ARRAY_LEN];
    sourceArray[0] = 1;
    sourceArray[1] = 2;

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
 
    while(1)
    {
    	count +=1;
    	if(count < 100)
        	write(sockfd, c, sizeof(c)+1);
        read(sockfd,recvline,100);
        printf("%s",recvline);
    }
    // write(sockfd, sourceArray, sizeof(int) * ARRAY_LEN);
    printf("sent!!!");
}

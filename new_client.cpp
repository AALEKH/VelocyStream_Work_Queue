#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <velocypack/vpack.h>


#define PORT_NO 3033
#define BUFFER_SIZE 1024

using namespace arangodb::velocypack;

struct velocystream{
  uint32_t length;
  uint32_t chunkx; // chunkx = chunk + isFirstChunk
  uint64_t messageId;
  arangodb::velocypack::Builder vpacks; // Collection of all Velocypacks
};

const char* constructVstream(char stre[BUFFER_SIZE], int cnt){
  velocystream velocy_one;
  arangodb::velocypack::Builder build;
  velocy_one.length = sizeof(stre);
  velocy_one.chunkx = 1 | 0; // chunk + isFirstByte;
  velocy_one.messageId = cnt;
  build.add(Value(stre));
  velocy_one.vpacks = build;
  // velocystream *srt_l = (velocystream *)malloc(1000);
  return (static_cast<char*>(static_cast<void*>(&velocy_one)));
}

int main()
{
int sd;
arangodb::velocypack::Builder build;
arangodb::velocypack::Builder build_two;
ValueLength len;
int count = 0;
velocystream velocy_one, velocy_two;
struct sockaddr_in addr;
int addr_len = sizeof(addr);
char buffer[BUFFER_SIZE] = "";
const char *sendBuffer;
// Create client socket
if( (sd = socket(PF_INET, SOCK_STREAM, 0)) < 0 )
{
  perror("socket error");
  return -1;
}

bzero(&addr, sizeof(addr));

addr.sin_family = AF_INET;
addr.sin_port = htons(PORT_NO);
addr.sin_addr.s_addr =  htonl(INADDR_ANY);

// Connect to server socket
if(connect(sd, (struct sockaddr *)&addr, sizeof addr) < 0)
{
  perror("Connect error");
  return -1;
}

while (strcmp(buffer, "q") != 0)
{
  // Read input from user and send message to the server
  gets(buffer);
  count++;
  sendBuffer = constructVstream(buffer, count);
  // build.add(Value(buffer));

  send(sd, sendBuffer, sizeof(sendBuffer), 0);
  // Receive message from the server
  // printf("String sent !!!!!");
  // recv(sd, &build_two, 1000, 0);
  printf("message:%s\n", sendBuffer);
  recv(sd, buffer, 2000, 0);
  // Slice s(build.start());  
  printf("Size of Send Buffer %lu\n", sizeof(sendBuffer));
  // printf("message: %s\n", s.copyString().c_str());
  // Slice s(build.start());
  // printf("vpack is: %s", s.copyString().c_str());
}

return 0;
}

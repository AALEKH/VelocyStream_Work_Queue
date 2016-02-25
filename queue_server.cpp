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

int main()
{
    map<uint32_t,int> messageCount;
    Options dumperOptions;
    dumperOptions.prettyPrint = true;
    std::string result;
    StringSink sink(&result);
    Dumper dumper(&sink, &dumperOptions);
    map<uint32_t, vector<string>> messages;
    int count[2];
    Builder builder;
    char str[100], str2[4];
    int listen_fd, comm_fd;
 
    struct sockaddr_in servaddr;
 
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
 
    bzero( &servaddr, sizeof(servaddr));
 
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htons(INADDR_ANY);
    servaddr.sin_port = htons(22000);
 
    bind(listen_fd, (struct sockaddr *) &servaddr, sizeof(servaddr));
 
    listen(listen_fd, 10);
 
    comm_fd = accept(listen_fd, (struct sockaddr*) NULL, NULL);
 
    while(1)
    {
        read(comm_fd, &builder, 100);
        Slice s(builder.start());
        dumper.dump(s);
        std::cout << "Resulting JSON:" << std::endl << result << std::endl;
         // cout << "The size of recieved messageCOunt is: " << sizeof(count) << endl;
 
    }
}

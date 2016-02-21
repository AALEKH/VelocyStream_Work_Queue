#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

//For Vpack objects
#include <velocypack/vpack.h>

using namespace std;
using namespace arangodb::velocypack;

int main()
{
    sockaddr_in serv;
    bzero(&serv, sizeof(serv));
    serv.sin_family=AF_INET;
    serv.sin_port=htons(3345);
    inet_aton("127.0.0.1", &(serv.sin_addr));

    int servfd=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    bind(servfd, (sockaddr*)(&serv), sizeof(serv));

    listen(servfd, 5);
    sockaddr cli;
    int connfd;
    pid_t id=-1;
    socklen_t siz=sizeof(cli);
    while(true)
    {
        if( (connfd=accept(servfd, &cli, &siz)) >=0 )
            continue;
    }
}
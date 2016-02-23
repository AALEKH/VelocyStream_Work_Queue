#include <map>
#include <stdio.h>
#include <vector>
#include "iostream"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

using namespace std;

int main()
{
    map<uint32_t,int> messageCount;
    int count[2];
    //count[12345] = 5;
    map<uint32_t, vector<string> > vpackMap;
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
 
 //       bzero( str, 100);
 
        read(comm_fd, count, sizeof(count));
        cout << "The size of recieved messageCOunt is: " << sizeof(count) << endl;
        //cout << "Echoing back - " << str << "size" << (unsigned)strlen(str)<<  " 0: "<< str[0]<< " 1: " << str[1] << endl;
        //if((str[0] == 'h') &&(str[1] == 'e')){
        //    str2[0] = 't';
        //    str2[1] = 'o'; 
        //    str2[2] = 't';
        //    str2[3] = 'o';;
        //    write(comm_fd, str2, strlen(str2));
        // }//else{
        //     write(comm_fd, str, strlen(str)); 
        // }
        //else{
        //     str = "hello-stranger, no access";
        //     write(comm_fd, str, strlen(str)+1);
        // }
 
    }
}

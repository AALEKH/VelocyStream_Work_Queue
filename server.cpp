// /*Required Headers*/
// #include <map>
// #include <sys/types.h>
// #include <sys/socket.h>
// #include <netdb.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <stdio.h>
// #include <string>
// #include <stdlib.h>  
 
// #define ARRAY_LEN 4

// using namespace std;

// int main()
// {
//     map<int, int> packCount;
//     map<int, string> streamValue;
//     char str[100];
//     int listen_fd, comm_fd, rea, intermediate;
//     string targetArray[ARRAY_LEN], string_intermediate;
//     struct sockaddr_in servaddr;
 
//     listen_fd = socket(AF_INET, SOCK_STREAM, 0);
 
//     bzero( &servaddr, sizeof(servaddr));
 
//     servaddr.sin_family = AF_INET;
//     servaddr.sin_addr.s_addr = htons(INADDR_ANY);
//     servaddr.sin_port = htons(22000);
 
//     bind(listen_fd, (struct sockaddr *) &servaddr, sizeof(servaddr));
 
//     listen(listen_fd, 10);
 
//     comm_fd = accept(listen_fd, (struct sockaddr*) NULL, NULL);
//     while(1){
//         rea = read(comm_fd, targetArray, sizeof(string) * ARRAY_LEN);
//         printf("%d", rea);
//         printf("Read !!");
//         if(!(rea < 1)) {

//             //Check if given packet is first velocystream packet
//             if(stoi(targetArray[3]) == 1) {
//                 // packCount.insert(pair<int,int>(stoi(targetArray[0]),stoi(targetArray[2])-1));
//                 packCount[stoi(targetArray[0])] = stoi(targetArray[2])-1;
//                 // streamValue.insert(pair<int,int>(stoi(targetArray[0]),stoi(targetArray[1])));
//                 streamValue[stoi(targetArray[0])] = stoi(targetArray[1]);
//             } else {
//                 intermediate = packCount.find(stoi(targetArray[0]))->second;
//                 packCount[stoi(targetArray[0])] = intermediate-1;
//                 string_intermediate = streamValue.find(stoi(targetArray[0]))->second;
//                 string_intermediate.append(targetArray[1]);
//                 streamValue[stoi(targetArray[0])] = string_intermediate;
//             }          

//             printf("Size of StreamValue: %d", streamValue.size());
//             break;
//         }
//     }
// }
/*Required Headers*/

// #include <iostream>    //cout
#include <stdio.h> //printf
#include <string.h>    //strlen
// #include <string>  //string
#include <sys/socket.h>    //socket
#include <arpa/inet.h> //inet_addr
#include <netdb.h> //hostent
#include <velocypack/vpack.h>




#include <sys/types.h>
// #include <sys/socket.h> //
// #include <netdb.h> //
#include <unistd.h>
// #include <stdio.h> //
// #include <iostream> 
// #include <map>
// #include <string> //
 
#define ARRAY_LEN 400

// using namespace std;

int main()
{
 
    char str[100];
    arangodb::velocypack::Builder builder;
    int listen_fd, comm_fd, rea;
    char targetArray[ARRAY_LEN];
    struct sockaddr_in servaddr;
 
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
 
    bzero( &servaddr, sizeof(servaddr));
 
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htons(INADDR_ANY);
    servaddr.sin_port = htons(22000);
 
    bind(listen_fd, (struct sockaddr *) &servaddr, sizeof(servaddr));
 
    listen(listen_fd, 10);
 
    comm_fd = accept(listen_fd, (struct sockaddr*) NULL, NULL);
    while(1){
        rea = read(comm_fd, &builder, 400);
        if(!(rea < 1)) {
            // printf("%s\n", targetArray[0].c_str());
            // printf("%s\n", targetArray[1].c_str());
            // printf("%s\n", targetArray[2].c_str());
            // printf("%s\n", targetArray[3].c_str());
            // if(stoi(targetArray[3]) == 1){
            //     printf("Hey there sexy you are right ;)");
            // }
            // break;
            printf("Received something !!!");
        }
    }
}
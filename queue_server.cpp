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
    cout << "error-1" << endl;
    map<uint32_t,int> messageCount;
    Options dumperOptions;

    // Builder b = Null;
    dumperOptions.prettyPrint = true;
    std::string result;
    StringSink sink(&result);
    Dumper dumper(&sink, &dumperOptions);
    cout << "error-2" << endl;
    map<uint32_t, vector<string>> messages;
    int count[2];
    Builder builder;
    char str[100], str2[4];
    int listen_fd, comm_fd;
 
    struct sockaddr_in servaddr;
 
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
 
    bzero( &servaddr, sizeof(servaddr));
 
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); //htons("127.0.0.1")
    servaddr.sin_port = htons(22000);
    cout << "error-3" << endl;
    bind(listen_fd, (struct sockaddr *) &servaddr, sizeof(servaddr));
    cout << "error-5" << endl;
    listen(listen_fd, 10);
    cout << "error-4" << endl;
    comm_fd = accept(listen_fd, (struct sockaddr*) &servaddr, NULL);
    cout << "error-6:  "<< comm_fd << endl;
    while(1)
    {
        // cout << "e" << endl;
        read(comm_fd, &builder, 100);
        // cout << "read" << endl;
        Slice s(builder.start());
        // cout << s.type() << endl;
        if(s.type() != ValueType::None){
            printf("Type %s", s.type());
            // cout << s.type() << endl;
            // cout << "recieved" << endl;
        }else{
            // cout << "break" << endl;
            break;
        }
        // Slice s(builder.start());
        // dumper.dump(s);
        // std::cout << "Resulting JSON:" << std::endl << result << std::endl;
        // cout << "The size of recieved messageCOunt is: " << sizeof(result) << endl;
 
    }
}

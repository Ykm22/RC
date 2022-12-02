#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>

int main(){
    int c;
    struct sockaddr_in server;
    // uint16_t a, b, suma;
    c = socket(AF_INET, SOCK_STREAM, 0);
    if(c < 0){
        printf("Eroare la crearea socket-ului client\n");
        return 1;
    }

    //memset(&server, 0, sizeof(server));

    server.sin_family = AF_INET;
    server.sin_port = htons(8884);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    if(connect(c, (struct sockaddr *) &server, sizeof(server)) < 0){
        printf("Eroare la conectarea la server\n");
        return 1;
    }

    //uint16_t n;
    int n, x;
    printf("n = ");
    scanf("%d", &n);
    send(c, &n, sizeof(int), 0);

    printf("x = ");
    scanf("%d", &x);
    send(c, &x, sizeof(int), 0);

    // int* v = (int*)malloc(n * sizeof(int));
    // for(int i = 1; i <= n; i++){
    //     printf("i = %d", &i);
    //     scanf("%d", &x);
    //     printf("%d", x);
    //     send(c, &x, sizeof(int), 0)
    // }
    return 0;
}
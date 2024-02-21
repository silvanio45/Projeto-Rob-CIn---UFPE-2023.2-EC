#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_ADDRESS "127.0.0.1"
#define SERVER_PORT 8888

#define OPEN 1
#define CLOSE 0

void delay(int delayTime) {
    usleep(delayTime * 1000);
}

// void move(float p1 , float p2 ,float p3 ,float p4 ,float p5 ,float p6) {
//         movJoints(sock, buffer,p1, -p2, p3, -p4, p5, p6);
//         delay(2000);
// }

void initSocket(int* sock, char* buffer){

    struct sockaddr_in serv_addr;

    // Create a socket
    if ((*sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        exit(1);
    }

    // Set the server address and port
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, SERVER_ADDRESS, &serv_addr.sin_addr) <= 0) {
        printf("\n Invalid address/ Address not supported \n");
        exit(1);
    }

    // Connect to the server
    if (connect(*sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\n Connection Failed \n");
        exit(1);
    }
}

void movJoints(int sock, char* buffer, float j1, float j2, float j3, float j4, float j5,float j6, int state){
    sprintf(buffer, "%f,%f,%f,%f,%f,%f,%d", j1, j2, j3, j4, j5, j6, state);
    send(sock, buffer, strlen(buffer), 0);
    int valread = read(sock, buffer, 2048);
    printf("Result: %s\n", buffer);
}

int main(int argc, char *argv[]) {
    
    //variaveis para conexcao com o robo NAO MEXER
    int sock = 0;
    char buffer[2048] = {0};

    //conexao com o robo NAO MEXER
    initSocket(&sock, buffer);

    //Programe aqui ---------------------------------------------------

    while (1){
        // move(-0.219, -0.572, -0.620, -0.090, -0.4, -0.125);
        
       movJoints(sock, buffer, -1.63, -0.505, -0.733, -0.14, 0.02, -0.06, OPEN);
        delay(500);
     /*  movJoints(sock, buffer, -1.615, -0.284, -0.733, 0.009, -0.035, -0.130, CLOSE);
        delay(2000);
       movJoints(sock, buffer, -1.615, -0.284, -0.733, 0.009, -0.035, -0.130, OPEN);
        delay(500);
        movJoints(sock, buffer,-1.599, -0.505, -0.732, -0.258, -0.005, -0.0018, OPEN);
       delay(500);
       movJoints(sock, buffer,-1.599, -0.505, -0.732, -0.258, -0.005, -0.0018, CLOSE);
       delay(2500);
       movJoints(sock, buffer, -1.615, -0.284, -0.733, 0.009, -0.035, -0.130, CLOSE);
        delay(500);
        movJoints(sock, buffer,-0.219, -0.572, -0.620, -0.090, -0.4, -0.125, CLOSE);
       delay(500);
        movJoints(sock, buffer,-0.219, -0.572, -0.620, -0.090, -0.4, -0.125, OPEN);
       delay(500);
       movJoints(sock, buffer, -1.615, -0.284, -0.733, 0.009, -0.035, -0.130, CLOSE);
        delay(500);*/
    }

    //-----------------------------------------------------------------

    // Encerra a conexao NAO MEXER
    close(sock);

    return 0;
}

// Script PORTSCAN
// 13.10.2019

// para usar o printf
#include <stdio.h>        // printf(), perror()
#include <sys/types.h>    // AF_INET, SOCK_STREAM
#include <sys/socket.h>   // socket(), connect()
#include <netinet/in.h>   // struct sockaddr_in
#include <arpa/inet.h>    // htons(), inet_addr()
#include <unistd.h>       // close()

int main(int argc, char *argv[]){
    int meusocket;
    int conecta;

    int porta;
    int inicio = 0;
    int final = 65535;
    char *destino;
    destino = argv[1];

    // usa essa struct para implementar o protoolo ip  
    struct sockaddr_in alvo;

    for (porta=inicio;porta<final;porta++){

        meusocket = socket(AF_INET,SOCK_STREAM,0);
        // agora partimos para construcao que se encontra no "man ip"
        alvo.sin_family = AF_INET;
        alvo.sin_port = htons(porta);
        // o inet_addr eh para converter o endereco de forma correta
        alvo.sin_addr.s_addr = inet_addr(destino);

        // fazendo a conexao, procure com o comando "man connect"
        // sizeof alvo = para pegar o tamanho
        conecta = connect(meusocket, (struct sockaddr *)&alvo, sizeof alvo);

        if(conecta == 0){
            printf("Porta %d - Status [ABERTA] \n",porta);
            close(meusocket);
            close(conecta);
        }else{
            //printf("Porta fechada \n");
            close(meusocket);
            close(conecta);
    }
    }   
}
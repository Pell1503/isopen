#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32

#include <winsock2.h>

#else

#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#endif


int porta_aberta(const char *ip, int porta) {

    int sock;
    struct sockaddr_in alvo;

    
    sock = socket(AF_INET, SOCK_STREAM, 0);

#ifdef _WIN32

    if (sock == INVALID_SOCKET) {
        return 0;
    }

#else

    if (sock < 0) {
        return 0;
    }

#endif

    
    alvo.sin_family = AF_INET;
    alvo.sin_port = htons(porta);

    
    alvo.sin_addr.s_addr = inet_addr(ip);

    if (alvo.sin_addr.s_addr == INADDR_NONE) {

#ifdef _WIN32
        closesocket(sock);
#else
        close(sock);
#endif

        return 0;
    }

   
    if (connect(sock, (struct sockaddr *)&alvo, sizeof(alvo)) == 0) {

#ifdef _WIN32
        closesocket(sock);
#else
        close(sock);
#endif

        return 1;
    }

   
#ifdef _WIN32
    closesocket(sock);
#else
    close(sock);
#endif

    return 0;
}


int main(int argc, char *argv[]) {

#ifdef _WIN32

    WSADATA wsa;

    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {

        printf("Erro ao iniciar Winsock.\n");

        return 1;
    }

#endif


    
    if (argc != 4) {

        printf("\nUso:\n");
        printf("%s <IP> <porta_inicial> <porta_final>\n\n", argv[0]);

        printf("Exemplo:\n");
        printf("%s 127.0.0.1 1 100\n\n", argv[0]);

#ifdef _WIN32
        WSACleanup();
#endif

        return 1;
    }


    
    char *ip = argv[1];

    int inicio = atoi(argv[2]);
    int fim = atoi(argv[3]);


    printf("\n================================\n");
    printf("       TCP PORT SCANNER\n");
    printf("================================\n");

    printf("IP: %s\n", ip);
    printf("Portas: %d - %d\n\n", inicio, fim);


   
    for (int porta = inicio; porta <= fim; porta++) {

        if (porta_aberta(ip, porta)) {

            printf("[+] Porta %d ABERTA\n", porta);

        }

    }


#ifdef _WIN32

    WSACleanup();

#endif

    return 0;
}
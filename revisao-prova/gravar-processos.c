#include <stdio.h>
#include <unistd.h>

int main () {
    pid_t pid;
    int status;
    FILE* ponteiro_arquivo;
    int contador = 0;

    pid = fork();
    if(pid == 0) {
        ponteiro_arquivo = fopen("gravando-processos.txt", "a");
        printf("Processo filho (PID: %d) em execução\n", getpid());
        for(int i = 0; i < 100; i++) {
            contador++;
            fprintf(ponteiro_arquivo, "Processo filho %d\n", i);
        }
    } else {
        ponteiro_arquivo = fopen("gravando-processos.txt", "a");
        printf("Processo pai (PID: %d) em execução\n", getpid());
        for(int i = 0; i < 100; i++) {
            contador++;
            fprintf(ponteiro_arquivo, "Processo pai %d\n", i);
        }
    }


    //fprintf(ponteiro_arquivo, "escrevendo...\n");
    //fputs("mais texto\n", ponteiro_arquivo);
    fclose(ponteiro_arquivo);

    printf("gravação em arquivo feita com sucesso!\n");

    return 0;
}
#include <stdio.h>    // Para a função printf
#include <unistd.h>   // Para as funções fork, getpid, getppid
#include <sys/wait.h> // Para a função wait

int main() {
    pid_t pid_filho;

    printf("--- [PAI] Iniciando o processo principal. Meu PID é %d\n", getpid());

    pid_filho = fork();

    if (pid_filho < 0) {
        fprintf(stderr, "Erro ao criar o processo filho.\n");
        return 1; 
    }

    if (pid_filho == 0) {
        printf(" -> [FILHO] Eu sou o processo filho. Meu PID é %d e o PID do meu pai é %d\n", getpid(), getppid());

        pid_t pid_neto;
        pid_neto = fork();

        if (pid_neto < 0) {
            fprintf(stderr, "Erro ao criar o processo neto.\n");
            return 1;
        }

        if (pid_neto == 0) {
            printf("   --> [NETO] Eu sou o processo neto. Meu PID é %d e o PID do meu pai (o filho) é %d\n", getpid(), getppid());
        } else {
            wait(NULL);
            printf(" -> [FILHO] Meu processo neto terminou. Agora vou encerrar.\n");
        }

    } else {
        printf("--- [PAI] Criei um processo filho com PID %d\n", pid_filho);

        wait(NULL);

        printf("--- [PAI] Meu processo filho terminou. O programa será finalizado.\n");
    }

    return 0;
}
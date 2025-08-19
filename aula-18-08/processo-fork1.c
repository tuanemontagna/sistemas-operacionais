#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;

    pid = fork(); // Cria um novo processo

    if (pid < 0) {
        // Se fork() retornar um valor negativo, significa que a criação do processo falhou
        printf("Erro ao criar processo.\n");
        return 1;
    } else if (pid == 0) {
        // Código executado pelo processo filho
        printf("Processo filho:\n");
        printf("O PID do processo filho é: %d\n", getpid());
        printf("O PID do processo pai é: %d\n", getppid());
    } else {
        // Código executado pelo processo pai
        printf("Processo pai:\n");
        printf("O PID do processo pai é: %d\n", getpid());
        printf("O PID do processo filho é: %d\n", pid);
    }

    return 0;
}
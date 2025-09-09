#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída
#include <unistd.h> // Inclui a biblioteca para chamadas ao sistema POSIX, como fork() e execve()
#include <sys/wait.h> // Inclui a biblioteca para chamadas de espera de processos, como waitpid()

int main() {
    pid_t pid; // Declara uma variável do tipo pid_t para armazenar o PID do processo filho
    int status; // Variável para armazenar o status de retorno do processo filho

    // Cria um novo processo filho
    pid = fork();

    if (pid < 0) {
        // Se fork() retornar um valor negativo, ocorreu um erro na criação do processo filho
        perror("Erro ao criar o processo filho");
        return 0;
    } else if (pid == 0) {
        // Código executado pelo processo filho
        printf("Processo filho (PID: %d) em execução\n", getpid());
        sleep(2); // Simula algum trabalho com sleep de 2 segundos
        printf("Processo filho (PID: %d) finalizado\n", getpid());
        return 0; // Termina o processo filho
    } else {
        // Código executado pelo processo pai
        printf("Processo pai esperando pelo processo filho\n");
        // Espera pelo término do processo filho usando waitpid()
        waitpid(pid, &status, 0); // Aguarda o processo filho terminar
        printf("Processo pai finalizado\n");
    }

    return 0; // Termina o processo pai
}
#include <stdio.h>
#include <stdlib.h>

int main () {
    //pid_t pid;
    FILE* ponteiro_arquivo;

    ponteiro_arquivo = fopen("gravando-arquivo.txt", "w");

    if(ponteiro_arquivo == NULL) {
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }

    fprintf(ponteiro_arquivo, "escrevendo...\n");
    fputs("mais texto\n", ponteiro_arquivo);
    fclose(ponteiro_arquivo);

    printf("gravação em arquivo feita com sucesso!\n");

    return 0;
}
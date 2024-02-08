#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **Arquivo(int *cont){
    FILE *file;
    file = fopen("votos.txt", "r");
    if(file == NULL){
        printf("O Arquivo não pode ser aberto!");
        exit(1);
    }

    *cont = 0;
    char **votos = (char **) malloc(sizeof(char *));
    if (votos == NULL) {
        printf("Não foi possível alocar memória!");
        exit(1);
    }

    char str[3];
    while(fscanf(file, "%2s", str) == 1){
        votos[*cont] = strdup(str);
        (*cont)++;
        char **temp = (char **) realloc(votos, (*cont+1) * sizeof(char *));
        if (temp == NULL) {
            printf("Não foi possível alocar memória!");
            for(int i = 0; i < *cont; i++)
                free(votos[i]);
            free(votos);
            exit(1);
        }
        votos = temp;
    }

    fclose(file);
    return votos;
}

int main() {
    
    char **votos = NULL;
    int cont = 0;

    votos = Arquivo(&cont);

    for(int i = 0; i<cont; i++){
        printf("%s\n", votos[i]);
        free(votos[i]);
    }
    free(votos);
    return 0;
}

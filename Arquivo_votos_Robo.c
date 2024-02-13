#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **Arquivo(int *cont){
    /*
    Cria um ponteiro do tipo file, abre o arquivo votos.txt e ler o arquivo ("r")
    */
    FILE *file;
    file = fopen("votos.txt", "r");
    /*
    verifica se o arquivo pode ser aberto, arquivo != NULL
    */
    if(file == NULL){
        printf("O Arquivo não pode ser aberto!");
        exit(1);
    }
    /*
    inicia o contador de votos
    */
    *cont = 0;
    char **votos = (char **) malloc(sizeof(char *)); // cria um ponteiro duplo para armazerar os votos (votos[][])
    if (votos == NULL) { // verifica se é possivel alocar memoria
        printf("Não foi possível alocar memória!");
        exit(1);
    }

    char str[3]; // declara uma string de tamanho 3 para receber cada voto
    while(fscanf(file, "%5s", str) == 1){ // lê cada voto do arquivo até o final
    votos[*cont] = strdup(str); // copia o voto para o vetor de votos na posição cont
    (*cont)++; // incrementa o contador de votos
    char **temp = (char **) realloc(votos, (*cont+1) * sizeof(char *)); // realoca o vetor de votos para ter mais uma posição
    if (temp == NULL) { // verifica se a realocação foi bem sucedida
        printf("Não foi possível alocar memória!"); // imprime uma mensagem de erro
        for(int i = 0; i < *cont; i++) // percorre o vetor de votos
            free(votos[i]); // libera a memória alocada para cada voto
        free(votos); // libera a memória alocada para o vetor de votos
        exit(1); // encerra o programa com código de erro
    }
    votos = temp; // atualiza o ponteiro de votos para apontar para o novo vetor
}

    fclose(file); // fecha o arquivo
return votos; // retorna o vetor de votos
}

int main() {
    
    char **votos = NULL; // declara um ponteiro duplo para receber os votos
    int cont = 0; // declara uma variável para receber o número de votos

    votos = Arquivo(&cont); // chama a função Arquivo e passa o endereço da variável cont

    for(int i = 0; i<cont; i++){ // percorre o vetor de votos
        printf("%s\n", votos[i]); // imprime cada voto na tela
        free(votos[i]); // libera a memória alocada para cada voto
    }
    free(votos); // libera a memória alocada para o vetor de votos
    return 0; // encerra o programa
}

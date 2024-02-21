#include <stdio.h>

int main()
{
    char mat[3][3];
    int trava = 0;
    int entX, entY, cont = 0;
    char entC;
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            mat[i][j] = '\0';
        }
    }
        
    while(trava == 0){
        scanf("%c: (%d,%d)", &entC, &entX, &entY);
        
        
        if(mat[entX][entY] == '\0'){
            mat[entX][entY] = entC;
            cont++;
        }
        
        if((mat[0][0] == mat[1][1] && mat[1][1] == mat[2][2]) && mat[0][0] != '\0'){
            printf("O ganhador foi: %c", mat[0][0]);
            trava = 1;
        } else if((mat[0][2] == mat[1][1] && mat[1][1] == mat[2][0]) && mat[0][2] != '\0'){
            printf("O ganhador foi: %c", mat[0][2]);
            trava = 1;
        } else {
            for(int i = 0; i<3; i++){
                if((mat[i][0] == mat[i][1] && mat[i][1] == mat[i][2]) && mat[i][0] != '\0'){
                    printf("O ganhador foi: %c", mat[i][0]);
                    trava = 1;
                }
            }
            for(int j = 0; j<3; j++){
                if((mat[0][j] == mat[1][j] && mat[1][j] == mat[2][j]) && mat[0][j] != '\0'){
                    printf("O ganhador foi: %c", mat[0][j]);
                    trava = 1;
                }
            }
            if(cont == 9){
                printf("Fim :)");
                trava = 1;
            }
        }
    }
    printf("\n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%c", mat[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

#include <cstdio>

int a[100][100],b[100][100],c[100][100];
int kola,bara,kolb,barb;
int main(){
    scanf("%d%d", &bara,&kola);
    for(int i=0; i<bara; i++){
        for(int j=0; j<kola; j++){
            scanf("%d", &a[i][j]);
        }
    }
    scanf("%d%d", &barb,&kolb);
    for(int i=0; i<barb; i++){
        for(int j=0; j<kolb; j++){
            scanf("%d", &b[i][j]);
        }
    }
    
    for(int i=0; i<bara; i++){
        for(int j=0; j<kolb; j++){
           for(int k=0; k<kola; k++){
               c[i][j]=c[i][j]+a[i][k]*b[k][j];
           }
        }
    }
    for(int i=0; i<bara; i++){
        for(int j=0; j<kolb; j++){
            printf("%d", c[i][j]);
            if(j!=kolb-1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}

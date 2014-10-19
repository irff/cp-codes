#include <cstdio>

int bar,kol;
int a[200][200];
int main(){
    scanf("%d%d", &bar,&kol);
    for(int i=0; i<bar; i++){
        for(int j=0; j<kol; j++){
            scanf("%d", &a[i][j]);
        }
    }
    for(int i=0; i<kol; i++){
        for(int j=bar-1; j>=0; j--){
            printf("%d", a[j][i]);
            if(j!=0) printf(" ");
        }
        printf("\n");
    }
    return 0;
}

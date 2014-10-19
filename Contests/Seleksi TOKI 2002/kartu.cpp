#include <cstdio>
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int m[1000][3];
int map[1000];
int n,ntebak,tebakan;
void shuffle() {
    int tmp[1000][3];
    R(i,0,n/3) R(j,0,3) tmp[i][j]=m[i][j];
    int ni=0,nj=0; 
    R(i,0,3) {
        R(j,0,n/3) {
            m[ni][nj++]=tmp[j][i];
            if(nj==3) nj=0,ni++;
        }
    }
}

int main() {
    scanf("%d", &n);
    int x=1;
    R(i,0,n/3) R(j,0,3) m[i][j]=x++;
    scanf("%d", &ntebak);
    R(i,0,ntebak) {
        scanf("%d", &tebakan);
        R(j,0,n/3) {
            map[ m[j][tebakan-1] ]++;
        }
        shuffle();
    }
    R(i,1,n+1) {
        if(map[i]==ntebak) printf("%d ", i);
    }
    printf("\n");
    return 0;
}

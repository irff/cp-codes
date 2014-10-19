#include <cstdio>

int a[100][100],b[100][100],n;
int main(){
    scanf("%d%d", &n,&n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &a[i][j]);
        }
    }
    scanf("%d%d", &n,&n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &b[i][j]);
        }
    }
    
    int state=1;
    
    // identik
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(a[i][j]!=b[i][j]) state=0;
        }
    }
    if(state) { printf("identik\n"); return 0; }
    // vertikal
    state=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(a[i][j]!=b[i][n-j-1]) state=0;
        }
    }
    if(state) { printf("vertikal\n"); return 0; }
    // horizontal
    state=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(a[i][j]!=b[n-i-1][j]) state=0;
        }
    }
    if(state) { printf("horisontal\n"); return 0; }
    // diagonal kanan bawah
    state=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(a[i][j]!=b[j][i]) state=0;
        }
    }
    if(state) { printf("diagonal kanan bawah\n"); return 0; }
    
    // diagonal kiri bawah
    state=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(a[i][j]!=b[n-j-1][n-i-1]) state=0;
        }
    }
    if(state) { printf("diagonal kiri bawah\n"); return 0; }
    printf("tidak identik\n");
    
    return 0;
}

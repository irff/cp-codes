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
    
    // 0
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(a[i][j]!=b[i][j]) state=0;
        }
    }
    if(state) { printf("0\n"); return 0; }
    // 90
    state=1;
    for(int i=0; i<n; i++){
        for(int j=n-1; j>=0; j--){
            if(a[j][i]!=b[i][n-j-1]) state=0;
        }
    }
    if(state) { printf("90\n"); return 0; }
    // 180
    state=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(a[i][j]!=b[n-i-1][n-j-1]) state=0;
        }
    }
    if(state) { printf("180\n"); return 0; }
    // 270
    state=1;
    for(int i=n-1; i>=0; i--){
        for(int j=0; j<n; j++){
            if(a[j][i]!=b[n-i-1][j]) state=0;
        }
    }
    if(state) { printf("270\n"); return 0; }
    printf("tidak sama\n");
    
    
    return 0;
}

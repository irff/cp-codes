#include <cstdio>

int n;
int a[100][100];
int main() {
    scanf("%d", &n);
    a[0][0]=1;
    for(int i=1; i<n; i++) {
        a[0][i] = a[0][i-1]+i+1;
        a[i][0] = a[i-1][0]+i+1;
    }
    for(int i=1; i<n; i++) {
        for(int j=1; j<n; j++) a[i][j]=a[i-1][j]+a[i][j-1];
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
        printf("%d ", a[i][j]);
        printf("\n");
    }
    return 0;
}

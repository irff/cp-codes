#include <cstdio>
using namespace std;

int a[100][100];
int n;
int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &a[0][i]);
    for(int i=1; i<n; i++){
        for(int j=0; j<(n-1); j++) a[i][j]=a[i-1][j+1]-a[i-1][j];
    }
    for(int i=0; i<n; i++) {
        if(i==n-1){
            printf("%d",a[i][0]);
        } else printf("%d ", a[i][0]);
    }
    printf("\n");
    return 0;
}

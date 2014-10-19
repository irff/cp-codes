#include <cstdio>
#include <algorithm>
using std::max;
int a[200][200];
int n;
int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            scanf("%d", &a[i][j]);
        }
    }
    for(int i=n-2; i>=0; i--){
        for(int j=0; j<=i; j++){
            a[i][j]=a[i][j]+max(a[i+1][j],a[i+1][j+1]);
        }
    }
    printf("%d\n", a[0][0]);
}

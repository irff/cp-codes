#include <cstdio>
#include <algorithm>
using namespace std;
#define modar 1000007

int f[210][21000];
int teskes,n,k;
int main(){
    for(int i=1; i<=200; i++){
        f[i][0]=1;
        for(int j=1; j*2<=i*(i-1); j++){
            f[i][j]=f[i][j-1]+f[i-1][j];
            if(j>=i) f[i][j]-=f[i-1][j-i];
            f[i][j]= (f[i][j]+modar) % modar;
        }
    }
    scanf("%d", &teskes);
    while(teskes--){
        scanf("%d%d", &n, &k);
        printf("%d\n", f[n][k]);
    }
    return 0;
}

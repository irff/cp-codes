#include <cstdio>
#include <cmath>
using namespace std;

long long a[20][20];
int num;
int main(){
    a[1][1]=1;
    for(int i=2; i<=16; i++){
        a[i][1]=i+a[i-1][1];
        a[1][i]=i+a[1][i-1];
        a[i][i]=a[i][i-1]+a[i-1][i];
    }
    for(int i=2; i<=16; i++){
        for(int j=2; j<=16; j++){
            a[i][j]=a[i][j-1]+a[i-1][j];
        }
    }
    scanf("%d", &num);
    for(int i=1; i<=num; i++){
        for(int j=1; j<=num; j++){
           if(j==num)printf("%lld",a[i][j]);
           else
           printf("%lld ",a[i][j]);
        }
        printf("\n");
    }
    
    
    return 0;
}

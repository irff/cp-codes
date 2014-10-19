#include <cstdio>

long long a[20][20];
int x,y;
int main(){
    scanf("%d%d", &x, &y);
    for(int i=0; i<=10; i++)
     for(int j=0; j<=i; j++){
         if(i==0) a[i][j]=1;
         else if(i!=j) a[i][j]=a[i][j-1]+a[i-1][j];
         else a[i][j]=a[i][j-1];
     }
    printf("%d\n", a[x][y]);
    scanf("\n");
    return 0;
}

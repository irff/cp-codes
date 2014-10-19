// DP Triangle
// Input :
// N, a triangle of number, calculate the maximum sum from top to bottom
// Can only walk to the exact bottom, or the left bottom
// in:
// 4
// 5
// 1 2
// 8 2 4
// 4 7 4 1
// out:
// 21

#include <cstdio>
#include <algorithm>
using std:: max;

int n,x[100][100];

int F(int a, int b){
    if( b > a) return 0;
    if( a == n-1) return x[a][b];
    return x[a][b]+max( F(a+1,b), F(a+1,b+1) );

}
int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++) 
      for(int j=0; j<=i; j++) 
        scanf("%d", &x[i][j]);
    
    printf("%d\n", F(0,0));
    scanf("\n");
    return 0;
}

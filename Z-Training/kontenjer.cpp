#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define INF 2000111222
int a[3][3],total,minz;
int main(){
    minz=INF;
    R(i,0,3) R(j,0,3) scanf("%d", &a[i][j]),total+=a[i][j];
    R(i,0,3)
     R(j,0,3)
      R(k,0,3)
       if(i!=j and i!=k and k!=j) minz=min(minz,total-a[0][i]-a[1][j]-a[2][k]);
    printf("%d\n", minz);
    scanf("\n");
    return 0;
}

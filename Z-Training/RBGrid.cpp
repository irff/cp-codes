#include <cstdio>
#include <cstring>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

char m[1002][1002];
int hasil,bar,kol;
int main(){
    scanf("%d%d", &bar, &kol);
    R(i,0,bar) scanf("%s", &m[i]);
    
    R(i,1,bar-1)
     R(j,1,kol-1){
      if(m[i][j]=='B' and m[i-1][j]=='B' and m[i][j+1]=='B' and m[i+1][j]=='B' and m[i][j-1]=='B')
       hasil++;
    }
    printf("%d\n", hasil);
    return 0;
}

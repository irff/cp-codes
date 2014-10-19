#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)
 
int bar, kol, n;
long long ans = 0;
char m[600][600];
long long v[600][600];
int main() {
    memset(m, '.', sizeof m);
    scanf("%d%d%d", &bar, &kol, &n);
     
    kol+=2;
    R(i,0,n) {
        int ai,aj,bi,bj;
        scanf("%d%d%d%d", &ai, &aj, &bi, &bj);
        ai--; aj--; bi--; bj--;
        aj+=1; bj+=1;
        R(j,ai,bi+1) R(k,aj,bj+1) m[j][k]='X';
        if(aj-1 >= 0) m[ai][aj-1]='A';
        if(bj+1 < kol) m[ai][bj+1]='A';
    }
    /*
    R(j,0,kol) v[bar][j]=1, m[bar][j]='X';
    bar++;
    */
    /*
    R(i,0,bar) {
        R(j,0,kol) printf("%c", m[i][j]);
        printf("\n");
    }
    */
    //R(i,0,bar) R(j,0,kol) printf("%d%c", v[i][j], j==kol-1?'\n':' ');
     
    RV(i,bar-1,0) {
        R(j,0,kol) {
            if(m[i][j]=='A') {
              int ai = 0, num = 0;
              R(k,i+1,bar) {
                if(m[k][j]=='X' or k==bar-1) { ai=k; break; }
              }
              num = v[ai][j];
              int ki = j, ka = j;
              ki--,ka++;
              if(i==0 or !(m[i-1][j-1]=='X')) while(ki     and m[i][ki]=='X') v[i][ki]+=num, ki--;
              if(i==0 or !(m[i-1][j+1]=='X')) while(ka<kol and m[i][ka]=='X') v[i][ka]+=num, ka++;
            }
        }
        R(j,0,kol) if(m[i][j]=='X') v[i][j]+=1;
    }
    R(j,0,kol) {
        int ai = 0;
        while(ai<bar and m[ai][j]!='X') ai++;
        long long num = v[ai][j];
        //if(ai < bar-2) num+=2;
        //printf("%d %d %d\n", ai, j, num);
        ans = max(ans, num);
    }
    printf("%lld\n", ans);
    /*
    R(i,0,bar) {
        R(j,0,kol) printf("%d ", v[i][j]);
        printf("\n");
    }
    */
    return 0;
}

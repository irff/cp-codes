#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <iostream>
#include <string>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

typedef long long LLD;
typedef pair<int,int> II;

int teskes;
int bar,kol,change, maks = -2000111222;
int a[300][20], memo[102][12][102];

int rek(int i, int j, int change) {
    if( i >= bar) return 0;
    if(memo[i][j][change]==0) {
      int maks = rek(i+1,j,change) + a[i][j];
      if(change > 0)
      for(int x = 0; x<kol; x++) {
          if(x != j) maks = max(maks, rek(i+1, x, change-1)+a[i][j]);
      }
      return memo[i][j][change] = maks;
    }
    return memo[i][j][change];
    
}

int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        memset(memo, 0, sizeof memo);
        maks = -2000111222;
        scanf("%d%d%d", &bar, &kol, &change);
        R(i,0,bar) R(j,0,kol) scanf("%d", &a[i][j]);
        
        R(i,0,kol) maks = max(maks, rek(0,i,change));
        printf("%d\n", maks);
    }

    return 0;
}

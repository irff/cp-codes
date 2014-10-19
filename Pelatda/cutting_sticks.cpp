#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n, x[100], len;
int memo[120][120];
int rek(int a, int b) {
    if(memo[a][b]==-1) {
      if(b-a == 1) return memo[a][b]=0;
      int ans = 2000111222;
      R(i,a+1,b) {
        ans = min(ans, rek(a,i)+rek(i,b)+(x[b]-x[a]));
      }
      return memo[a][b]=ans;
    }
    return memo[a][b];
}

int main() {
    scanf("%d", &len);
    while(len!=0) {
        memset(memo, -1, sizeof memo);
        scanf("%d", &n);
        n+=2;
        x[0] = 0;
        R(i,1,n-1) scanf("%d", &x[i]);
        x[n-1]=len;
        //for(int i=0; i<n; i++) printf("%d ", x[i]);
        int ans = rek(0,n-1);
        printf("The minimum cutting is %d.\n", ans);
        scanf("%d", &len);
    }

    return 0;
}

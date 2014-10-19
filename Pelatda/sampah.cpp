#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int teskes, n, a[1000];
int m[120][51000];
int rek(int k, int sisa) {
    if(m[k][sisa]==-1) {
      if(k >= n) return m[k][sisa]=0;
      int x = rek(k+1, sisa);
      if(sisa >= a[k]) x = max(x, rek(k+1, sisa-a[k])+a[k]);
      return m[k][sisa]=x;
    }
    return m[k][sisa];
}

int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        memset(m, -1, sizeof m);
        int sum = 0;
        scanf("%d", &n);
        R(i,0,n) { scanf("%d", &a[i]); sum+=a[i]; }
        int half = sum/2;
        int x = rek(0,half);
        printf("%d\n", abs(sum-2*x));
    }
    return 0;
}

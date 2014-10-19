/*
    ID: irfan1
    LANG: C++
    TASK: money
*/
#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n, duit, c[12000];
long long a[12000];
int main() {
    freopen("money.in", "r", stdin);
    freopen("money.out", "w", stdout);
    scanf("%d%d", &n, &duit);
    R(i,0,n) scanf("%d", &c[i]);
    a[0]=1;
    R(i,0,n) {
      for(int j=c[i]; j<=duit; j++) {
          a[j]+=a[j-c[i]];
      }
    }
    printf("%lld\n", a[duit]);
    return 0;
}

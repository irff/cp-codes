#include <cstdio>
#include <algorithm>
using namespace std;

int n, a[200], b[200], memo[102][102];

int rek(int ki, int ka) {
    if(memo[ki][ka]==0) {
      if(ki >= n or ka >= n) return 0;
      if(a[ki] == b[ka]) {
        return memo[ki][ka] = 1+rek(ki+1,ka+1);
      }
      return memo[ki][ka] = max(rek(ki+1,ka), rek(ki,ka+1));
    }
    return memo[ki][ka];
}

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    for(int i=0; i<n; i++) scanf("%d", &b[i]);
    int hasil = rek(0,0);
    printf("%d\n", hasil);
    return 0;
}

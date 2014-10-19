#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

const int INF = 2000111222;
typedef long long LLD;
int n, a[200];
LLD ans = 0;

int main() {
    scanf("%d", &n);
    R(i,0,n+1) {
        scanf("%d", &a[i]);
    }
    ans = rek(0,n);
    printf("%lld\n", ans);
    return 0;
}

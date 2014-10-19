#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int teskes, n, num;
int main() {
    scanf("%d", &teskes);
    R(k,0,teskes) {
        scanf("%d", &n);
        int maks = 0;
        R(i,0,n) {
            scanf("%d", &num);
            maks = max(num, maks);
        }
        printf("Case %d: %d\n", k+1, maks);
    }
    return 0;
}

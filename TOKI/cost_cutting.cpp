#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int a[10], teskes;
int main() {
    scanf("%d", &teskes);
    R(i,0,teskes) {
        scanf("%d%d%d", &a[0], &a[1], &a[2]);
        sort(a, a+3);
        printf("Case %d: %d\n", i+1, a[1]);
    }
    return 0;
}

/*
    ID: irfan1
    LANG: C++
    TASK: numtri
*/
#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

long long n, a[1200][1200];
long long maks=-1;
int main() {
    freopen("numtri.in", "r", stdin);
    freopen("numtri.out", "w", stdout);
    scanf("%lld", &n);
    R(i,0,n) {
        R(j,0,i+1) scanf("%d", &a[i][j]);
    }
    RV(i,n-2,0) {
        R(j,0,i+1) {
            a[i][j] = a[i][j] + max(a[i+1][j], a[i+1][j+1]);
        }
    }
    printf("%lld\n", a[0][0]);
    return 0;
}

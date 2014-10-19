#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

int n;
int a[100][100];
char sampah[100];
int main() {
    gets(sampah);
    scanf("%d", &n);
    R(i,0,n) {
        R(j,0,n) {
            scanf("%d", &a[i][j]);
        }
    }
    RV(i,n-2,0) {
        R(j,0,n) {
            a[i][j]+=max(a[i+1][j],a[i+1][j+1]);
        }
    }
    printf("%d\n", a[0][0]);
    return 0;
}

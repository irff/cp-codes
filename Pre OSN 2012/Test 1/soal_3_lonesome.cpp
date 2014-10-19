#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n, a[600], b[600], cowa, cowi;
long long maks=-1;
int main() {
    scanf("%d", &n);
    R(i,0,n) scanf("%d%d", &a[i], &b[i]);
    R(i,0,n) {
        R(j,i+1,n) {
            long long dist = labs(a[i]-a[j])*labs(a[i]-a[j]);
            dist += labs(b[i]-b[j])*labs(b[i]-b[j]);
            if(dist > maks) {
                maks = dist;
                cowa = i, cowi = j;
            }
        }
    }
    printf("%d %d\n", cowa+1, cowi+1);
    return 0;
}

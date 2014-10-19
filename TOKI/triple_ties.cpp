#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n, m[120][120];
int nsol = 0, a[1000111], b[1000111], c[1000111];

int main() {
    while( scanf("%d", &n) > 0) {
        nsol = 0;
        R(i,0,n) R(j,0,n) scanf("%d", &m[i][j]);
        R(i,0,n) {
            R(j,0,n) {
                R(k,0,n) {
                    if( (i < j and j < k or i > j and j > k) and ( m[i][j] and m[j][k] and m[k][i])) {
                        a[nsol] = i; b[nsol] = j; c[nsol] = k;
                        nsol++;
                    }
                    if( (i < j  and j < k) and !m[i][j] and !m[j][i] and !m[j][k] and !m[k][j] and !m[k][i] and !m[i][k]) {
                        a[nsol] = i; b[nsol] = j; c[nsol] = k;
                        nsol++;
                    }
                }
            }
        }
        printf("%d\n", nsol);
        R(i,0,nsol) printf("%d %d %d\n", a[i]+1, b[i]+1, c[i]+1);
    }

    return 0;
}

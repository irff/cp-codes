#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int na, nb, cc[10111], n, coin[3];
int main() {
    
    while( scanf("%d%d%d", &coin[0], &coin[1], &n) > 0) {
        memset(cc, 0, sizeof cc);
        R(i,0,2) {
            R(j,0,n+1) {
                if(j-coin[i] >= 0) {
                    cc[j] = max(cc[j], cc[j-coin[i]]+1);
                }
            }
        }
        if(cc[n] > 0) {
            printf("%d\n", cc[n]);
        } else {
            int minum=0, burger = 0;
            for(int i=n; i>=0; i--) {
                minum++;
                if(cc[i] > 0) {
                    burger = cc[i];
                    break;
                }
            }
            printf("%d %d\n", burger, minum);
        }
    }

    return 0;
}

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

const int INF = 10000;

int bar, kol;
int m[120][120];
int ans = 0;
int main() {
    scanf("%d%d", &bar, &kol);
    while(!(bar==0 and kol==0)) {
        ans = 0;
        R(i,0,bar) {
            R(j,0,kol) {
                int num; scanf("%d", &num);
                if(num==0) m[i][j] = 1;
                else m[i][j] = -INF;
            }
        }
        R(i,0,bar) {
            R(j,0,kol) {
                if(i>0) m[i][j]+=m[i-1][j];
                if(j>0) m[i][j]+=m[i][j-1];
                if(i>0 and j>0) m[i][j]-=m[i-1][j-1];
            }
        }
        /*
        R(i,0,bar) {
           R(j,0,kol) printf("%d ", m[i][j]);
           printf("\n");
        }*/
        R(i,0,bar) {
            R(j,0,kol) {
                R(k,i,bar) {
                    R(l,j,kol) {
                        int x = m[k][l];
                        if(i>0) x-=m[i-1][l];
                        if(j>0) x-=m[k][j-1];
                        if(i>0 and j>0) x+=m[i-1][j-1];
                        ans = max(ans, x);
                    }
                }
            }
        }
        printf("%d\n", ans);
        scanf("%d%d", &bar, &kol);
    }

    return 0;
}

#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n, maks = 0;
char s[200][200];
int main() {
    while(scanf("%d", &n) > 0) {
        maks = 0;
        R(i,0,n) scanf("%s", &s[i]);
        R(i,0,n) {
            R(j,0,n) {
                if(s[i][j]=='1') {
                    int mins = 2000111222;
                    R(k,0,n) {
                        R(l,0,n) {
                            if(s[k][l]=='3') {
                                mins = min(mins, abs(k-i)+abs(l-j));
                            }
                        }
                    }
                    maks = max(maks, mins);
                }
            }
        }
        printf("%d\n", maks);
    }
    return 0;
}

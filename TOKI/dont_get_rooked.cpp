#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef struct {
    char s[5][5];
} mep;

int n, p[5], ans = 0;
mep m;

void place(int ke, mep x) {
    R(i,0,n) {
        R(j,0,n) {
            if(x.s[i][j] == 'Q') {
                int a = i-1;
                while(a>=0 and x.s[a][j]!='X') {
                    if(x.s[a][j]=='Q') return ;
                    a--;
                }
                a = i+1;
                while(a<n and x.s[a][j]!='X') {
                    if(x.s[a][j]=='Q') return ;
                    a++;
                }
                int b = j-1;
                while(b>=0 and x.s[i][b]!='X') {
                    if(x.s[i][b]=='Q') return ;
                    b--;
                }
                b = j+1;
                while(b<n and x.s[i][b]!='X') {
                    if(x.s[i][b]=='Q') return ;
                    b++;
                }
            }
        }
    }
    /*
    R(i,0,n) {
        printf("%s\n", x.s[i]);
    }
    printf("\n");
    */
    R(i,0,n) {
        R(j,0,n) {
            if(x.s[i][j]!='X' and x.s[i][j]!='Q') {
                x.s[i][j] = 'Q';
                place(ke+1, x);
                x.s[i][j] = '.';
            }
        }
    }
    
    ans = max(ans, ke);
}

int main() {
    while(scanf("%d", &n) >0, n) {
        ans = 0;
        R(i,0,n) {
            scanf("%s", &m.s[i]);
        }
        place(0, m);
        printf("%d\n", ans);
    }
    return 0;
}

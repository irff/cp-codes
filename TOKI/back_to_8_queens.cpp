#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

int a[10];
int sol[100][10], nsol = 0;

typedef struct {
    bool x[10][10];
} board;

board sampah;

bool can(int a, int b, board m) {
    R(i,0,8) if(m.x[a][i]==1) return 0;
    R(i,0,8) if(m.x[i][b]==1) return 0;
    for(int i=a-1,j=b-1; i>=0 and j>=0; i--,j--) if(m.x[i][j]==1) return 0;
    for(int i=a-1,j=b+1; i>=0 and j<8; i--,j++) if(m.x[i][j]==1) return 0;
    for(int i=a+1,j=b+1; i<8 and j<8; i++,j++) if(m.x[i][j]==1) return 0;
    for(int i=a+1,j=b-1; i<8 and j>=0; i++,j--) if(m.x[i][j]==1) return 0;
    return 1;
}

void rek(int ke, board m) {
    if(ke>=8) {
        R(i,0,8) {
            R(j,0,8) {
                if(m.x[i][j]==1) {
                    sol[nsol][i] = j;
                }
            }
        }
        nsol++;
    }
    R(i,0,8) {
        if(can(ke,i,m)) {
            m.x[ke][i] = 1;
            rek(ke+1, m);
            m.x[ke][i] = 0;
        }
    }
}

int main() {
    rek(0, sampah);
    //printf("%d\n", nsol);
    /*
    R(i,0,nsol) {
        R(j,0,8) {
            printf("%d ", sol[i][j]);
        }
        printf("\n");
    }*/
    int kasus = 0;
    while( scanf("%d%d%d%d%d%d%d%d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5], &a[6], &a[7], &a[8]) > 0) {
        int ans = 2000111222; kasus++;
        R(i,0,nsol) {
            int beda = 0;
            R(j,0,8) {
                if(sol[i][j]!=a[j]-1) beda++;
            }
            ans = min(ans, beda);
        }
        printf("Case %d: %d\n", kasus, ans);
    }
    return 0;
}

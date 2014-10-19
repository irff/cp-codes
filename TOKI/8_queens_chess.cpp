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
    int teskes;
    scanf("%d", &teskes);
    bool tamax = 0;
    while(teskes--) {
        int a, b;
        scanf("%d%d", &a, &b);
        int x = 1;
        if(tamax) printf("\n");
        tamax = 1;
        printf("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n");
        
        printf("\n");   
        R(i,0,nsol) {
            if(sol[i][b-1]==a-1) {
                if(x<10) printf(" ");
                printf("%d", x);
                printf("      ");
                R(j,0,8) printf("%d%c", sol[i][j]+1, j==7?'\n':' ');
                x++;
            }
        }
    }
    return 0;
}

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

typedef struct {
    char s[9][9];
} board;

typedef pair<int, int> PII;
vector< vector<PII> > sol;
int teskes, col[10],b[9][9];
char m[9][9];

bool can(int a, int b, board m) {
    R(i,a+1,8) if(m.s[i][b]=='X') return 0;
    RV(i,a-1,0) if(m.s[i][b]=='X') return 0;
    R(j,b+1,8) if(m.s[a][j]=='X') return 0;
    RV(j,a-1,0) if(m.s[a][j]=='X') return 0;
    for(int i=a-1,j=b-1; i>=0 and j>=0; i--,j--) if(m.s[i][j] == 'X') return 0;
    for(int i=a-1,j=b+1; i>=0 and j<8; i--,j++) if(m.s[i][j] == 'X') return 0;
    for(int i=a+1,j=b+1; i<8 and j<8; i++,j++) if(m.s[i][j] == 'X') return 0;
    for(int i=a+1,j=b-1; i<8 and j>=0; i++,j--) if(m.s[i][j] == 'X') return 0;
    return 1;
}

void rek(int ke, board m) {
    //printf("%d\n", ke);
    if(ke==8) {
        vector<PII> x;
        R(i,0,8) {
            R(j,0,8) {
                if(m.s[i][j]=='X') x.push_back(PII(i,j));
            }
        }
        /*
        R(i,0,8) printf("%d ", x[i].second);
        printf("\n");
        */
        sol.push_back(x);
        return ;
    }
    R(i,0,8) {
        if(m.s[ke][i]!='X' and can(ke, i, m)) {
            m.s[ke][i] = 'X';
            rek(ke+1, m);
            m.s[ke][i] = '.';
        }
    }
}

int main() {
    board x;
    memset(x.s,'.', sizeof x.s);
    rek(0,x);
    int len = sol.size();
    scanf("%d", &teskes);
    while(teskes--) {
        R(i,0,8) R(j,0,8) scanf("%d", &b[i][j]);
        int ans = 0;
        R(i,0,len) {
            int now = 0;
            R(j,0,8) {
                now+=b[sol[i][j].first][sol[i][j].second];
            }
            ans = max(ans,now);
        }
        if(ans<10)         printf("    ");
        else if(ans<100)   printf("   ");
        else if(ans<1000)  printf("  ");
        else if(ans<10000) printf(" ");
        printf("%d\n", ans);
    }
    
    return 0;
}

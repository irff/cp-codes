#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

int bar, kol, n, posx, posy, arah, collected;
char m[200][200], ins[51000];
int dx[4] = {-1, 0, 1, 0 };
int dy[4] = {0,  1, 0, -1};
int main() {
    while(scanf("%d%d%d", &bar, &kol, &n), bar and kol and n) {
        collected = 0;
        R(i,0,bar) scanf("%s", &m[i]);
        R(i,0,bar)
            R(j,0,kol)
                if(m[i][j]>='A' and m[i][j]<='Z') {
                    if(m[i][j] == 'N') arah = 0;
                    if(m[i][j] == 'L') arah = 1;
                    if(m[i][j] == 'S') arah = 2;
                    if(m[i][j] == 'O') arah = 3;
                    posx = i, posy = j;
                }
                
        scanf("%s", &ins);
        R(i,0,n) {
            if(ins[i] == 'D') {
                arah=(arah+1)%4;
            } else if(ins[i] == 'E') {
                arah=(arah+3)%4;
            } else {
                int nx = posx+dx[arah], ny = posy+dy[arah];
                if(nx<0 or ny<0 or nx>=bar or ny>=kol or m[nx][ny]=='#') continue;
                if(m[ posx = nx ][ posy = ny ] == '*') collected++, m[posx][posy] = '.';
            }
        }
        printf("%d\n", collected);
    }
    return 0;
}

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef long long LLD;

int teskes, nlempar, ngilir;
char s[120][120];
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%d%d", &nlempar, &ngilir);
        char dum; scanf("%c", &dum);
        int puguh = 0, cuk_norris = 0;
        R(i,0,ngilir) {
            R(j,0,nlempar) {
                scanf("%c", &s[i][j]);
            }
        }
        R(i,0,ngilir) {
            R(j,0,nlempar) {
                if(i%2==0) {
                    if(s[i][j]=='H') puguh++;
                } else {
                    if(s[i][j]=='H') cuk_norris++;
                }
            }
        }
    }

    return 0;
}

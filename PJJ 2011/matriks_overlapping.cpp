#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int bara, kola, barb, kolb;
int a[30][30], b[30][30];
int main() {
    scanf("%d%d", &bara, &kola);
    R(i,0,bara) R(j,0,kola) scanf("%d", &a[i][j]);
    scanf("%d%d", &barb, &kolb);
    R(i,0,barb) R(j,0,kolb) scanf("%d", &b[i][j]);
    // brood forst
    R(i,0,bara+barb-1) {
        R(j,0,kola+kolb-1) {
            
        }
    }
    return 0;
}

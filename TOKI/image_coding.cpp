#include <cstdio>
#include <functional>
#include <algorithm>
#include <cstring>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int teskes, kasus = 0;
int bar, kol, gede, kecil;
int m[300];
char s[30][30];
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        kasus++;
        R(i,0,30) m[i] = 0;
        scanf("%d%d%d%d", &bar, &kol, &gede, &kecil);
        R(i,0,bar) scanf("%s", &s[i]);
        R(i,0,bar) {
            R(j,0,kol) {
                m[ s[i][j] -'A' ]++;
            }
        }
        sort(m, m+26, greater<int>());
        //R(i,0,27) printf("%d %d\n", i, m[i]);
        int x = m[0], c = 1, total = m[0];
        while(m[c] == x) {
            total+=m[c];
            c++;
        }
        int ans = total*gede+(bar*kol-total)*kecil;
        printf("Case %d: %d\n", kasus, ans);
    }
    return 0;
}

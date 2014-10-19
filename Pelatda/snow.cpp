#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int teskes, bar, kol, m[200][200],ans=0,hasil = 0;
char s[1000];

void cek(int a, int b, int step) {
    hasil = max(hasil, step);
    if(a>0 and m[a-1][b]     > m[a][b]) cek(a-1,b,step+1);
    if(b<kol-1 and m[a][b+1] > m[a][b]) cek(a,b+1,step+1);
    if(a<bar-1 and m[a+1][b] > m[a][b]) cek(a+1,b,step+1);
    if(b>0 and m[a][b-1]     > m[a][b]) cek(a,b-1,step+1);
      
}

int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        hasil = 0;
        scanf("%s %d %d", &s, &bar, &kol);
        R(i,0,bar) {
            R(j,0,kol) {
                scanf("%d", &m[i][j]);
            }
        }
        R(i,0,bar) {
            R(j,0,kol) {
                cek(i,j,1);
            }
        }
        printf("%s: %d\n", s, hasil);
    }
    return 0;
}

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int bar, kol, d[120][120];
char s[120][120], color = 'a';
int main() {
    scanf("%d%d", &bar, &kol);
    R(i,0,bar) R(j,0,kol) scanf("%d", &d[i][j]);
    memset(s, 0, sizeof s);
    R(i,0,bar) R(j,0,kol) {
        if(s[i][j] == 0) {
            int posa = 999, posi = 999, mins = 200111222;
            if(i>0) if(mins > d[i-1][j] and d[i][j] > d[i-1][j]) posa = i-1, posi = j, mins = d[i-1][j];
            if(j>0) if(mins > d[i][j-1] and d[i][j] > d[i][j-1]) posa = i, posi = j-1, mins = d[i][j-1];
            if(j<kol-1) if(mins > d[i][j+1] and d[i][j] > d[i][j+1]) posa = i, posi = j+1, mins = d[i][j+1];
            if(i<bar-1) if(mins > d[i+1][j] and d[i][j] > d[i+1][j]) posa = i+1, posi = j, mins = d[i+1][j];
            printf("%d %d - %d %d %d %c\n", i, j, posa, posi, mins, color);
            //kalau danau
            if(mins == 200111222 and s[i][j] == 0) {
                s[i][j] = color;
                color++;
            //mengalirkan
            } else if(s[posa][posi]==0) {
                s[i][j] = color, s[posa][posi] = color;
                color++;
            //dialiri
            } else {
                s[i][j] = s[posa][posi];
            }
        }
    }
    R(i,0,bar) {
        printf("%s\n", s[i]);
    }
    return 0;
}

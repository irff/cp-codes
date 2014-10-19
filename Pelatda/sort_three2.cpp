/*
    ID: irfan1
    LANG: C++
    TASK: sort3
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int n, sa[1200], sb[1200], swp=0;
int gf[4][4], f[10];

int main() {
    freopen("sort3.in", "r", stdin);
    freopen("sort3.out", "w", stdout);
    scanf("%d", &n);
    for(int i=0; i<n; i++) { scanf("%d", &sa[i]); f[ sa[i] ]++; }
    int len = 0;
    for(int i=1; i<=3; i++) {
        for(int j=0; j<f[i]; j++) gf[i][ sa[len++] ]++;
    }
    
    //reduce 2 from group 1;
    int mins = min(gf[1][2], gf[2][1]);
    gf[1][2] -= mins;
    gf[2][1] -= mins;
    gf[1][1] += mins;
    gf[2][2] += mins;
    swp += mins;
    
    //reduce 3 from group 1;
    mins = min(gf[1][3], gf[3][1]);
    gf[1][3] -= mins;
    gf[3][1] -= mins;
    gf[1][1] += mins;
    gf[3][3] += mins;
    swp += mins;
    
    mins = f[1] - gf[1][1];
    swp += mins;
    
    //reduce 3 from group 2;
    gf[1] [1] = f [1];
    gf[2] [1] = gf[3] [1] = 0;
    gf[3] [2] += gf[1] [2];
    gf[2] [3] += gf[1] [3];
    gf[1] [2] = gf[1] [3] = 0;
    
    swp += gf[2][3];
    
    printf("%d\n", swp);
    return 0;
}

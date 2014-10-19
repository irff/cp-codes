#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <iostream>
#include <string>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

typedef long long LLD;
typedef pair<int,int> II;

int teskes;
int bar, kol, a[1000][1000], maks = -2000111222;
int main() {
    scanf("%d%d", &bar, &kol);
    R(i,0,bar) R(j,0,kol) scanf("%d", &a[i][j]);
    R(i,1,bar) R(j,0,kol) {
        if(j == 0) a[i][j] = max(a[i-1][j], a[i-1][j+1])+a[i][j];
        else if(j==kol-1) a[i][j] = max(a[i-1][j],a[i-1][j-1])+a[i][j];
        else a[i][j] = max(a[i-1][j], max(a[i-1][j-1],a[i-1][j+1]))+a[i][j];
    }
    R(i,0,kol) maks = max(maks, a[bar-1][i]);
    printf("%d\n", maks);

    return 0;
}

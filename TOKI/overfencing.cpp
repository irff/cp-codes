#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int bar, kol;
char m[1000][1000];
int main() {
    scanf("%d%d", &kol, &bar);
    kol = 2*kol+1;
    bar = 2*bar+1;
    R(i,0,bar) {
        gets(m[i]);
    }
    R(i,0,bar) {
        printf("%s\n", m[i]);
    }

    return 0;
}

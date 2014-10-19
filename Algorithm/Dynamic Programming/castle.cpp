#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++) 

int bar, kol;
int con;
char m[200][200];
void place(int a, int b, int con) {
    m[2*a+1][2*b+1]='.';
    if(con&(1<<0)) m[2*a+1][2*b]='#';
    if(con&(1<<1)) m[2*a][2*b+1]='#';
    if(con&(1<<2)) m[2*a+1][2*b+2]='#';
    if(con&(1<<3)) m[2*a+2][2*b+1]='#';
}

int main() {
    memset(m, 'X', sizeof m);
    scanf("%d%d", &kol, &bar);
    R(i,0,bar) {
        R(j,0,kol) { scanf("%d", &con); place(i,j,con); }
    }
    R(i,0,2*bar) {
        R(j,0,2*kol) printf("%c", m[i][j]);
        printf("\n");
    }
    return 0;
}

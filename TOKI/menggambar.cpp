#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n;
char m[20][20];

void fill(int a, int b) {
    R(i,'A','Z'+1) {
        if(a>0 and m[a-1][b]==i) continue;
        if(a<n-1 and m[a+1][b]==i) continue;
        if(b>0 and m[a][b-1]==i) continue;
        if(b<n-1 and m[a][b+1]==i) continue;
        m[a][b] = i;
        break;
    }
}

int main() {
    scanf("%d", &n);
    R(i,0,n) scanf("%s", &m[i]);
    R(i,0,n) {
        R(j,0,n) {
            if(m[i][j]=='.') {
                fill(i,j);
            }
        }
    }
    R(i,0,n) printf("%s\n", m[i]);
    return 0;
}

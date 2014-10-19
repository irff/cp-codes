#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int dbar[8]={-1,-1,0,1,1,1,0,-1};
int dkol[8]={0,1,1,1,0,-1,-1,-1};

int teskes, bar, kol, donat=0;
char s[120][120];
int m[120][120];

void dfs(int a, int b, int com) {
    if(a >= 0 and a < bar and b >= 0 and b < kol and m[a][b]==1) {
        m[a][b]=com;
        R(i,0,8) dfs(a+dbar[i], b+dkol[i], com);
    }
}

bool caridonat(int a, int b, int com, int sebelah) {
    bool jadi = 1;
    if(m[a][b]!=0 and m[a][b] < 20000) {
        if(m[a][b]!=sebelah) return 0;
        return 1;
    }
    if( m[a][b] == 0) {
        m[a][b]=com;
        for(int i=0; i<8; i+=2) {
            if( !caridonat(a+dbar[i],b+dkol[i],com,sebelah) ) jadi=0;
        }
        return jadi;
    }
    return jadi;
}

void dfsdonat(int a, int b, int com) {
    if(m[a][b]==com) {
        m[a][b]=-2*com;
        for(int i=0; i<8; i+=2) {
            dfsdonat(a+dbar[i], b+dkol[i],com);
        }
    }
}

bool jadidonat(int a, int b, int sebelah) {
    bool jadi=1;
    if(m[a][b] < -20000) {
        if(m[a][b]!=sebelah) return 0;
        return 1;
    }
    if(m[a][b] > 0 and m[a][b] < 20000) {
        m[a][b]=99999;
        R(i,0,8) {
            if(!jadidonat(a+dbar[i], b+dkol[i], sebelah)) jadi=0;
        }
        return jadi;
    }
    return jadi;
}

int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        donat=0;
        memset(m, -1, sizeof m);
        scanf("%d%d", &bar, &kol);
        R(i,0,bar) scanf("%s", s[i]);
        bar+=2; kol+=2;
        R(i,1,bar-1) R(j,1,kol-1) m[i][j]=s[i-1][j-1]-'0';
        int com=1;
        R(i,0,bar) R(j,0,kol)
            if(m[i][j]==1) dfs(i,j,++com);
        com = 20000;
        R(i,1,bar-1) R(j,1,kol-1) {
            if(m[i][j]==0) {
                if( caridonat(i,j,++com, m[i][j-1]) ) {
                    dfsdonat(i,j,com);
                }
            }
        }
        R(i,1,bar-1) R(j,1,kol-1) {
            if(m[i][j] < -20000 and m[i][j-1] > 0 and m[i][j-1] < 20000) {
                if(jadidonat(i,j-1,m[i][j]) ) donat++;
            }
        
        }
        printf("%d\n", donat);
        /*R(i,0,bar) {
            R(j,0,kol) printf("%d ", m[i][j]);
            printf("\n");
        }*/
    }

    return 0;
}

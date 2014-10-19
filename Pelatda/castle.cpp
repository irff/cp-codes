/*
    ID: irfan1
    LANG: C++
    TASK: castle
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++) 
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

int bar, kol;
int con, luas = 0, nruang=0, maks=0, maksi=0, posa=0, posi=0, arah=0;
char m[200][200], mi[200][200];
void place(int a, int b, int con) {
    m[2*a+1][2*b+1]='o';
    if(!(con&(1<<0))) m[2*a+1][2*b]='.';
    if(!(con&(1<<1))) m[2*a][2*b+1]='.';
    if(!(con&(1<<2))) m[2*a+1][2*b+2]='.';
    if(!(con&(1<<3))) m[2*a+2][2*b+1]='.';
}

void dfs(int a, int b) {
    if(a>=0 and b>=0 and a<bar and b<kol and m[a][b]!='#') {
        if(m[a][b]=='o') luas++;
        m[a][b]='#';
        dfs(a-1,b);
        dfs(a,b+1);
        dfs(a+1,b);
        dfs(a,b-1);
    }
}

void setup() {
    R(i,0,bar) R(j,0,kol) m[i][j]=mi[i][j];
}

int main() {
    memset(m, '#', sizeof m);
    freopen("castle.in", "r", stdin);
    freopen("castle.out", "w", stdout);
    scanf("%d%d", &kol, &bar);
    R(i,0,bar) {
        R(j,0,kol) { scanf("%d", &con); place(i,j,con); }
    }
    bar = bar*2+1;
    kol = kol*2+1;
    R(i,0,bar) R(j,0,kol) mi[i][j]=m[i][j];
    R(i,0,bar) {
        R(j,0,kol) {
            if(m[i][j]!='#') {
                nruang++;
                luas = 0;
                dfs(i,j);
                maks = max(maks, luas);
            }
        }
    }
    setup();
    R(j,0,kol) {
        RV(i,bar-1,0)  {
            
            if(m[i][j]=='o') {
                
                //atas
                setup(); m[i-1][j]='.'; luas = 0; dfs(i-1,j);
                if(luas > maksi) maksi=luas,posa=i/2,posi=j/2,arah=2;

                //kanan
                setup(); m[i][j+1]='.'; luas = 0; dfs(i,j+1);
                if(luas > maksi) maksi=luas,posa=i/2,posi=j/2,arah=3;
                
                
                //kiri
                setup(); m[i][j-1]='.'; luas = 0; dfs(i,j-1);
                if(luas > maksi) maksi=luas,posa=i/2,posi=j/2,arah=0;
                
                //bawah
                setup(); m[i+1][j]='.'; luas = 0; dfs(i+1,j);
                if(luas > maksi) maksi=luas,posa=i/2,posi=j/2,arah=1;
                setup();
            }
        }
    }
    printf("%d\n%d\n%d\n", nruang, maks, maksi);
    printf("%d %d ", posa+1, posi+1);
    if(arah==0) printf("W\n");
    if(arah==1) printf("S\n");
    if(arah==2) printf("N\n");
    if(arah==3) printf("E\n");
    /*
    setup();
    R(i,0,bar) {
        R(j,0,kol) printf("%c", m[i][j]);
        printf("\n");
    }
    */
    return 0;
}

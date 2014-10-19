#include <algorithm>
#include <cstdio>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

int now=0,nilai=0,nilai2=0,maks=0,bar,kol,m[100][100],mo[100][100],ori[100][100],belom[100][100];

void dfs(int a, int b, bool mana) {
    if(a>=0 and a<bar and b>=0 and b<kol) {
        if(mana == 0 and m[a][b]==now) {
            m[a][b] = 0;
            nilai++;
            dfs(a-1,b,mana);
            dfs(a,b+1,mana);
            dfs(a+1,b,mana);
            dfs(a,b-1,mana);
        } else if(mana==1 and mo[a][b]==now) {
            mo[a][b] = 0;
            nilai2++;
            dfs(a-1,b,mana);
            dfs(a,b+1,mana);
            dfs(a+1,b,mana);
            dfs(a,b-1,mana);
        }
    }
}

void runtuhkan() {
    RV(i,bar-1,0) {
        R(j,0,kol) {
            if(mo[i][j]==0) {
                int c=i;
                while(c > 0 and mo[c][j] == 0) {
                    c--;
                }
                mo[i][j]=mo[c][j];
                mo[c][j]=0;
            }
        }
    }
}

int main() {
    scanf("%d%d", &bar, &kol);
    R(i,0,bar) R(j,0,kol) { scanf("%d", &m[i][j]); mo[i][j] = ori[i][j] = belom[i][j] = m[i][j];}
    R(i,0,bar) R(j,0,kol) 
      if(m[i][j]!=0 and belom[i][j]!=0) {
        nilai = 0;
        now=m[i][j];
        dfs(i,j,0);
        R(k,0,bar) R(el,0,kol) if(m[k][el]==0) belom[k][el]=0;
        
        now=mo[i][j];
        dfs(i,j,1);
        
        runtuhkan();
        maks=max(nilai*(nilai-1),maks);
        R(k,0,bar) R(el,0,kol) {
            if(mo[k][el]!=0) {
                nilai2 = 0;
                now=mo[k][el];
                dfs(k,el,1);
                maks = max(nilai*(nilai-1)+nilai2*(nilai2-1),maks);
            }
        }
        R(k,0,bar) R(el,0,kol) m[k][el] = ori[k][el],mo[k][el] = ori[k][el];
      }
    printf("%d\n",maks);
    return 0;
}

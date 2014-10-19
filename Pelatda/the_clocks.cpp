/*
    ID: irfan1
    LANG: C++
    TASK: clocks
*/
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define pub(_a,_b) push_back(pii(_a,_b))
#define pa pub(0,0)
#define pb pub(0,1)
#define pc pub(0,2)
#define pd pub(1,0)
#define pe pub(1,1)
#define pf pub(1,2)
#define pg pub(2,0)
#define ph pub(2,1)
#define pi pub(2,2)
typedef vector<int> vi;
typedef pair<int,int> pii;
vector<pii> v[9];
int m[5][5], ans[30];
map<vi,bool> mep;
bool memo[4][4][4][4][4][4][4][4][4];
void rek(vi d, int step) {
    if( memo[d[0]][d[1]][d[2]][d[3]][d[4]][d[5]][d[6]][d[7]][d[8]] == 1) return ;
    memo[d[0]][d[1]][d[2]][d[3]][d[4]][d[5]][d[6]][d[7]][d[8]]=1;
    
    if(step == -1) R(i,0,9) { vi x = d; x[i]++; rek(x, step+1); }
    
    int a[5][5];
    R(i,0,3) R(j,0,3) a[i][j]=m[i][j];
    R(i,0,9) {
        R(j,0,v[i].size()) {
            int px = v[i][j].first, py = v[i][j].second;
            a[ px ] [ py ] = (a[ px ] [ py ]+3*d[i])%12;
        }
    }
    //R(i,0,3) { R(j,0,3) printf("%d ", a[i][j]); printf("\n"); }
    //printf("\n");
    int sum = 0;
    R(i,0,3) R(j,0,3) sum+=a[i][j];
    if(sum==0) {
        int ctr=0;
        R(i,0,9) {
            R(j,0,d[i]) ans[ctr++]=i+1;
        }
        R(i,0,ctr) printf("%d%c", ans[i],(i==ctr-1)?'\n':' ');
        return ;
    }
    R(i,0,9) { vi x = d; if(x[i]<3) { x[i]++; rek(x,step+1); } }
}

int main() {
    freopen("clocks.in", "r", stdin);
    freopen("clocks.out", "w", stdout);
    vi dum; dum.assign(9,0);
    v[0].pa; v[0].pb; v[0].pd; v[0].pe;
    v[1].pa; v[1].pb; v[1].pc;
    v[2].pb; v[2].pc; v[2].pe; v[2].pf;
    v[3].pa; v[3].pd; v[3].pg;
    v[4].pb; v[4].pd; v[4].pe; v[4].pf; v[4].ph;
    v[5].pc; v[5].pf; v[5].pi;
    v[6].pd; v[6].pe; v[6].pg; v[6].ph;
    v[7].pg; v[7].ph; v[7].pi;
    v[8].pe; v[8].pf; v[8].ph; v[8].pi;
    
    bool bisa = 1;
    R(i,0,3) R(j,0,3) { scanf("%d", &m[i][j]); m[i][j]%=12; if(m[i][j]!=0) bisa=0; }
    if(!bisa) rek(dum, -1);
    return 0;
}

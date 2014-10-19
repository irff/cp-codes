#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)
#define pb push_back
#define fs first
#define ls second
int nilai=0,bar,kol;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> II;
typedef pair<II,int> III;
typedef vector<III> VIII;
typedef pair<VVI, int> VVII;
VVI ori;

VVI runtuhkan(VVI x) {
    RV(i,bar-1,0) {
        R(j,0,kol) {
            if(x[i][j]==0) {
                int c=i;
                while(c > 0 and x[c][j] == 0) {
                    c--;
                }
                x[i][j]=x[c][j];
                x[c][j]=0;
            }
        }
    }
    return x;
}

VVII bfs(VVI m, int a, int b, int c) {
    int nilai = 0;
    queue<II> q;
    q.push(II(a,b));
    while(!q.empty()) {
        a=q.front().fs; b=q.front().ls; q.pop();
        if(m[a][b]==c) nilai++;
        m[a][b]=0;
        if(a-1>=0 and a-1<bar and b>=0 and b<kol and m[a-1][b]==c) q.push(II(a-1,b));
        if(a>=0 and a<bar and b+1>=0 and b+1<kol and m[a][b+1]==c) q.push(II(a,b+1));
        if(a+1>=0 and a+1<bar and b>=0 and b<kol and m[a+1][b]==c) q.push(II(a+1,b));
        if(a>=0 and a<bar and b-1>=0 and b-1<kol and m[a][b-1]==c) q.push(II(a,b-1));
    }
    return VVII(m,nilai);
}

VIII cari_kemungkinan(VVI m) {
    VIII v;
    VVII tm;
    R(i,0,bar) {
      R(j,0,kol) {
          if(m[i][j]!=0) {
            int x = m[i][j];
            tm=bfs(m,i,j,m[i][j]);
            m=tm.fs;
            if(tm.ls > 1) v.pb(III(II(i,j),x));
          }
      }
    }
    return v;
}

int rek(VVI m, int step) {
    VVII tm;
    /*R(i,0,bar) {
      R(j,0,kol) printf("%d ", m[i][j]);
      printf("\n");
    }*/
    //printf("\n");
    VIII v=cari_kemungkinan(m);
    int len=v.size(),maks=0;
    
    if(len==0 or step > 7) return maks;
    
    R(i,0,len) {
        tm = bfs(m, v[i].fs.fs, v[i].fs.ls, v[i].ls);
        VVI x = tm.fs;
        x = runtuhkan(x);
        int next_nilai = rek(x, step+1);
        maks=max(maks,tm.ls*(tm.ls-1)+next_nilai);
    }
    
    return maks;
}

int main() {
    scanf("%d%d", &bar, &kol);
    R(i,0,bar) {
        vector<int> v;
        R(j,0,kol) {
            int num;
            scanf("%d", &num);
            v.pb(num);
        }
        ori.pb(v);        
    }
    int hasil = rek(ori,0);
    printf("%d\n",hasil);
    return 0;
}

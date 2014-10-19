/*
    ID: irfan1
    LANG: C++
    TASK: lamps
*/
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)


int n, press, on[200], off[200], non=0, noff=0, num, ctr=0, nans=0, pencet[20];
bool b[20][200];
string ans[20];
int main() {
    memset(b,true,sizeof b);
    //freopen("lamps.in", "r", stdin);
    //freopen("lamps.out", "w", stdout);
    scanf("%d%d", &n, &press);
    
    scanf("%d", &num); while(num!=-1) { on[non++]=num-1; scanf("%d", &num); }
    scanf("%d", &num); while(num!=-1) { off[noff++]=num-1; scanf("%d", &num); }
    
    R(ia,0,2) R(ib,0,2) R(ic,0,2) R(id,0,2) {
        if(ia==1) R(i,0,n) b[ctr][i]=!b[ctr][i];
        if(ib==1) R(i,0,n) if(i%2==0) b[ctr][i]=!b[ctr][i];
        if(ic==1) R(i,0,n) if(i%2) b[ctr][i]=!b[ctr][i];
        if(id==1) R(i,0,n) if(i%3==0) b[ctr][i]=!b[ctr][i];
        
        bool jadi=1;
        /*
        R(i,0,ctr) {
          bool beda=0;
          R(j,0,n) {
              if(b[ctr][j]!=b[i][j]) beda=1;
          }
          if(!beda) jadi=0;
        }*/
        if(jadi) {
            pencet[ctr]=ia+ib+ic+id;
            /*
            printf("%d %d %d %d - ", ia, ib, ic, id);
            R(j,0,n) printf("%d", b[ctr][j]);
            printf("\n");
            */
            ctr++;
        }
    }
    /*
    R(i,0,non) printf("%d ", on[i]);
    printf("\n");
    R(i,0,noff) printf("%d ", off[i]);
    */
    R(i,0,ctr) {
        if(pencet[i]==0 and press%4==0) ;//diem
        else if(pencet[i]==1 and press%2==1 and press>=1) ;//diem
        else if(pencet[i]==2 and press%2==0 and press>=2) ;//diem
        else if(pencet[i]==3 and press%2==1 and press%3==0 and press>=3) ;//diem
        else continue;
        
        bool bisa=1;
        R(j,0,non) if(b[i][ on[j] ]==0) bisa=0;
        R(j,0,noff) if(b[i][ off[j] ]==1) bisa=0;
        if(bisa) {
            R(j,0,n) ans[nans].push_back( b[i][j]?'1':'0');
            nans++;
        }
    }
    if(nans==0) printf("IMPOSSIBLE\n");
    else {
        sort(ans, ans+nans);
        R(i,0,nans) {
            printf("\n--%d\n", i+1);
            printf("%s\n", ans[i].c_str());
        }
    }
    return 0;
}

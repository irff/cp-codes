#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define pb push_back
typedef vector<int> VI;
typedef vector<char> VC;

int teskes, n, a[10];
bool a2[13][13], a3[13][13][13], a4[13][13][13][13], a5[13][13][13][13][13];

void rek(VC v, int x, int n) {
    int m = n*(n-1)/2;
    if(x == m) {
        VI tmp(n,0);
        int ctr = 0; 
        R(i,0,n) R(j,i+1,n) {
                if(v[ctr]=='m') tmp[i]+=3;
                else if(v[ctr]=='k') tmp[j]+=3;
                else if(v[ctr]=='s') tmp[i]+=1,tmp[j]+=1;
                ctr++;
        }
        if(n==2) a2[ tmp[0] ][ tmp[1] ]=1;
        if(n==3) a3[ tmp[0] ][ tmp[1] ][ tmp[2] ]=1;
        if(n==4) a4[ tmp[0] ][ tmp[1] ][ tmp[2] ][ tmp[3] ]=1;
        if(n==5) a5[ tmp[0] ][ tmp[1] ][ tmp[2] ][ tmp[3] ][ tmp[4] ]=1;
        
    } else {
      v.pb('m');
      rek(v, x+1, n);
      v.pop_back(); v.pb('k');
      rek(v, x+1, n);
      v.pop_back(); v.pb('s');
      rek(v, x+1, n);
    }
}

int main() {
    VC v;
    R(i,2,6) rek(v,0,i);
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%d", &n);
        int maks=0;
        R(i,0,n) { scanf("%d", &a[i]); maks=max(maks,a[i]); }
        bool jadi = 0;
        if(maks <= 3*n-1){ 
          if(n==2) if(a2[ a[0] ][ a[1] ]) jadi=1;
          if(n==3) if(a3[ a[0] ][ a[1] ][ a[2] ]) jadi=1;
          if(n==4) if(a4[ a[0] ][ a[1] ][ a[2] ][ a[3] ]) jadi=1;
          if(n==5) if(a5[ a[0] ][ a[1] ][ a[2] ][ a[3] ][ a[4] ]) jadi=1;
        }
        if(jadi) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

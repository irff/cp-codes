#include <cstdio>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define pb(x) push_back(x)

typedef long long LLD;
typedef vector<int> VI;

bitset<50111> bs;
VI prim;
int plen = 0;
LLD n;

LLD pangkat(int a, int b) {
    if(b==0) return 1;
    LLD x = pangkat(a,b/2);
    if(b%2) {
        return x*x*a;
    }
    return x*x;
}

int main() {
    bs.set(); bs[1] = 0; bs[0] = 0;
    for(int i=2; i<=50000; i++) {
        if(bs[i]) {
            prim.pb(i); plen++;
            for(int j=i+i; j<=50000; j+=i) {
                bs[j] = 0;
            }
        }
    }
    //printf("%d\n", plen);
    //R(i,0,plen) printf("%d %d\n", i, prim[i]);
    while(scanf("%lld", &n), n) {
        vector<int> fak, pang;
        LLD x = n;
        for(int i=0; i<plen and x!=1; i++) {
            if(x%prim[i]==0) {
                fak.pb(prim[i]); pang.pb(0);
                while(x%prim[i]==0) {
                    x/=prim[i];
                    pang.back()++;
                }
            }
        }
        if(x!=1) fak.pb(x), pang.pb(1);
        int faklen = fak.size();
        LLD ans = 0;
        R(i,0,faklen) {
            ans+=pangkat(fak[i], pang[i]);
        }
        if(faklen==1) ans+=1;
        printf("%lld\n", ans);
    }

    return 0;
}

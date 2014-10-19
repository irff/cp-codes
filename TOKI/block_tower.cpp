#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

struct BlockTower {
       vector<int> b;
       int n, memo[60][60];
       int getTallest(vector<int> blockHeights) {
           b = blockHeights;
           n = b.size();
           memset(memo, -1, sizeof memo);
           int ret = rek(0, 0);
           return ret;
       }
       
       int rek(int ke, int tadi) {
           if(ke >= n) return 0;
           if(memo[ke][tadi]==-1) {
             int maks = 0;
             if(tadi==0 or tadi%2) {
                 if(b[ke]%2==1) maks = rek(ke+1, b[ke])+b[ke];
             }
             if(tadi%2==0) maks = max(maks, rek(ke+1, b[ke])+b[ke]);
             maks = max(maks, rek(ke+1, tadi));
             return memo[ke][tadi] = maks;
             
           }
           return memo[ke][tadi];
       }
       
};

BlockTower b;

int main() {
    vector<int> v;
    int n; scanf("%d", &n);
    R(i,0,n) {
        int x; scanf("%d", &x);
        v.push_back(x);
    }
    int ans = b.getTallest(v);
    printf("%d\n", ans);
    return 0;
}

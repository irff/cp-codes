/*
    ID: irfan1
    LANG: C++
    TASK: ariprog
*/
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n, m, upper, ans = 0;
bool cekbip[210000];
vector<int> bip;

int main() {
    freopen("ariprog.in", "r", stdin);
    freopen("ariprog.out", "w", stdout);
    scanf("%d%d", &n, &m);
    R(i,0,m+1) {
        R(j,i,m+1) {
            int num = i*i+j*j;
            if(!cekbip[num]) {
                bip.push_back(num);
                cekbip[num]=1;
            }
        }
    }
    int len = bip.size();
    sort(bip.begin(), bip.end());
    upper = m*m+m*m;
    
    int limit = upper/(n-1);
    for(int i=1; i<=limit; i++) {
        for(int j=0; j<len; j++) {
            bool bisa = 1;
            int awal = bip[j];
            for(int k=1; k<n; k++) {
                if(!cekbip[awal+k*i] or awal+k*i>upper) bisa=0;
                if(!bisa) break;
            }
            if(bisa) ans++,printf("%d %d\n", awal, i);
        }
    }
    if(ans==0) printf("NONE\n");
    return 0;
}

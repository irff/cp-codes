#include <cstdio>
#include <bitset>
#include <vector>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n, k;
bitset<1200> bs, gold;
vector<int> prim;
int main() {
    scanf("%d%d", &n, &k);
    bs.set(); bs[0] = 0; bs[1] = 0;
    for(int i=2; i*i<=n; i++) {
        for(int j=i*i; j<=n; j+=i) {
            bs[j] = 0;
        }
    }
    R(i,2,n+1) if(bs[i]) prim.push_back(i);
    int len = prim.size();
    R(i,0,len-1) {
        gold[prim[i]+prim[i+1]+1] = 1;
    }
    int c = 0;
    R(i,0,n+1) if(bs[i] and gold[i]) c++;
    if(c>=k) printf("YA\n");
    else printf("TIDAK\n");
    return 0;
}

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(long i=long(_a);i<long(_b);i++)
#define PLL pair<long,long>
long nmisil,nrumah,bom;
long r[100000];
vector<PLL>m;
int main(){
    scanf("%ld%ld", &nrumah, &nmisil);
    R(i,0,nrumah) scanf("%ld", &r[i]);
    R(i,0,nmisil){
        long n1,n2;
        scanf("%ld%ld", &n1, &n2);
        if(n1>n2) m.push_back(PLL(n1,n2));
        else m.push_back(PLL(n2,n1));
    }
    sort(r,r+nrumah);
    sort(m.begin(),m.end());
    R(i,0,nrumah){
        R(j,0,nmisil){
            if(r[i] <= m[j].first and r[i] >= m[j].second) { m[j].first=-1; m[j].second=-1; bom++; break; }
        }
    }
    printf("%ld\n", bom);
    return 0;
}

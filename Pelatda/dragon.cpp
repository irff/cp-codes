#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int dragon, knight, d[21000], k[21000];
int main() {
    scanf("%d%d", &dragon, &knight);
    while(dragon!=0 or knight!=0) {
        int chopped = 0, ctr = 0; long long ans = 0;
        
        R(i,0,dragon) scanf("%d", &d[i]);
        R(i,0,knight) scanf("%d", &k[i]);
        
        sort(d,d+dragon);
        sort(k,k+knight);
        
        R(i,0,dragon) {
            if(k[ctr] >= d[i]) ans+=(long long)k[ctr],chopped++;
            ctr++;
            if(ctr==knight) break;
        }
        
        if(chopped < dragon) printf("Loowater is doomed!");
        else printf("%lld\n", ans);
        
        scanf("%d%d", &dragon, &knight);
    }
    return 0;
}

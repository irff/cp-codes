#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef multiset<int> SI;

SI k;

int dragon, knight, d[21000];
int main() {
    SI::iterator it;
    scanf("%d%d", &dragon, &knight);
    while(dragon!=0 or knight!=0) {
        k.clear();
        int chopped = 0, ctr = 0, ans = 0;
        
        R(i,0,dragon) scanf("%d", &d[i]);
        R(i,0,knight) { int num; scanf("%d", &num); k.insert(num); }
        
        bool jadi = 1;
        R(i,0,dragon) {
            it = k.lower_bound(d[i]);
            if(it!=k.end()) {
                ans+=*it;
                k.erase(it);
            } else {
                jadi = 0;
                break;
            }
        }
        
        if(!jadi) printf("Loowater is doomed!\n");
        else printf("%d\n", ans);
        
        scanf("%d%d", &dragon, &knight);
    }
    return 0;
}

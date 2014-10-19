#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef pair<int,int> PII;
typedef pair<bool,PII> PBII;
map<int,PBII> m;
int main() {
    R(i,0,101) {
        R(j,i,101) {
            if(!m[j*j*j-i*i*i].first) {
                PBII x = PBII(1,PII(i,j));
                m[j*j*j-i*i*i] = x;
            }
        }
    }
    int n;
    while(scanf("%d", &n), n) {
        if(m[n].first) {
            printf("%d %d\n", m[n].second.second, m[n].second.first);
        } else printf("No solution\n");
    }
    return 0;
}

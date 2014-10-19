#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

typedef pair<int,int> PII;


PII a[120000];
int n,d[120000],s[120000],k[120000];
int main() {
    scanf("%d", &n);
    R(i,0,n) {
        scanf("%d", &d[i]);
        s[i]=d[i];
        a[i].first = d[i];
        a[i].second = i;
    }
    sort(a,a+n);
    sort(s,s+n);
    R(i,0,n) {
        int *pos = upper_bound(s,s+n,d[i]);
        int lok = pos-&s[0];
        bool nemu = 0;
        int minz = 2000111222;
        R(j,lok,n) {
            if(a[j].second > i) {
                nemu=1;
                minz=min(minz, a[j].second);
            }
        }
        if(!nemu) printf("0\n");
        else printf("%d\n", minz+1);
    }
    return 0;
}

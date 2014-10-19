#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)
#define pb push_back
#define pop pop_back

typedef pair<int,int> PII;
typedef vector<PII> VII;

VII v;
int n,a[120000],ans[120000],uk=0;
int main() {
    scanf("%d", &n);
    R(i,0,n) scanf("%d", &a[i]);
    RV(i,n-1,0) {
        if(i==n-1) { ans[i]=-1; v.pb(PII(a[i],i)); uk++; }
        else {
            int lim=uk;
            int j=lim-1;
            while(1) {
                if(v.empty()) {
                    ans[i]=-1;
                    v.pb(PII(a[i],i));
                    uk++;
                    break;
                } else if(a[i] >= v[j].first) {
                    v.pop(); uk--;
                } else {
                    ans[i]=v[j].second;
                    v.pb(PII(a[i],i));
                    uk++;
                    break;
                }
                j--;
            }
        }
    }
    //R(i,0,uk) printf("%d\n", v[i].first);
    R(i,0,n) printf("%d\n", ans[i]+1);
    return 0;
}

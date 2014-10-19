#include <cstdio>
#include <algorithm>
using namespace std;

bool a[200000];
int n, ctr=0, ans[200000];
int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    for(int i=1; i<=n; i++) {
        if(a[i]==1) {
            for(int j=i; j<=n; j+=i) {
                if(a[j]==1) a[j]=0;
                else a[j]=1;
            }
            ans[ctr++]=i;
        }
    }
    printf("%d\n", ctr);
    for(int i=0; i<ctr; i++) printf("%d\n", ans[i]);
    return 0;
}

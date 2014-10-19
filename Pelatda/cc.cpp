#include <cstdio>
#include <algorithm>
using namespace std;

int n, nk, k[1000], c[1000];
int main() {
    scanf("%d%d", &nk, &n);
    for(int i=0; i<nk; i++) scanf("%d", &k[i]);
    for(int i=0; i<=n; i++) c[i]=9999;
    c[0]=0;
    for(int i=1; i<=n; i++) {
        for(int j=0; j<nk; j++) {
            if(i-k[j]>=0) c[i]=min(c[i],c[i-k[j]]+1);
        }
    }
    for(int i=0; i<=n; i++) printf("%d %d\n", i, c[i]);
    
}

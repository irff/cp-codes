#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

const int INF = 2000111222;

int x[100111], a[100111], lis[100111], n=0, ans[100111];
int main() {
    while(scanf("%d", &a[n]) > 0) n++;
    R(i,1,n+1) x[i]=INF;
    x[0]=-INF; int now = 1,size=1;
    int maks = -2000111222, id = 0;
    //printf("n %d\n", n);
    for(int i=0; i<n; i++) {
    //    printf("%d ", a[i]);
        now = size;
        while(x[now-1]>=a[i]) now--;
        x[now]=a[i];
        lis[i]=now;
        if(lis[i] >= maks) maks=lis[i],id=i;
        if(now==size) size++;
    }
    //printf("\n");
    //printf("maks %d\nid %d\n", maks, id);
    for(int i=0; i<n; i++) printf("%d ", a[i]);
    printf("\n");
    for(int i = 0; i < n; ++i) {
            printf("%d ",lis[i]);
            }
            printf("\n");
    
    int ctr = maks, nans = maks;
    ans[ctr]=a[id];
    for(int i=id-1; i>=0; i--) {
        if(lis[i]==maks-1) {
            ctr--;
            ans[ctr] = a[i];
            maks = lis[i];
        }
    }
    printf("%d\n-\n", nans);
    for(int i=1; i<=nans; i++) printf("%d\n", ans[i]);
    
    return 0;
}

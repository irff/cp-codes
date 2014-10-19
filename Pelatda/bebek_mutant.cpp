#include <cstdio>
#include <algorithm>
using namespace std;

int n, a[100111], x[100111];
int maks = -2000111222;
int main() {
    scanf("%d", &n);
 
    for(int i=0; i<n; i++) { scanf("%d", &a[i]); maks=max(a[i], maks); }
 
    int ans = -2000111222;
    if(a[0]<0) a[0]=0;
    for(int i=1; i<n; i++) {
        if(a[i-1]+a[i]>0) a[i]+=a[i-1];
        else a[i]=0;
    }
    if(maks <= 0) {
        printf("%d\n", maks);
    } else {
        for(int i=0; i<n; i++) ans = max(ans, a[i]);
        printf("%d\n", ans);
    }
    //for(int i=0; i<n; i++)  printf("%d ", a[i]);
    
    return 0;
}

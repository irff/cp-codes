#include <cstdio>
#include <algorithm>
using namespace std;

int n, m;
int a[100200];
long long jumlah=0, maks=-2000111222333LL;
int main() {
    scanf("%d%d", &n, &m);

    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
        if(i<m-1) jumlah+=a[i];
        else {
            jumlah+=a[i];
            jumlah-=a[i-m];
            maks = max(jumlah, maks);
        }
    }
    printf("%lld\n", maks);
    
    
    return 0;
}

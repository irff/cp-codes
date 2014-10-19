#include <cstdio>
#include <algorithm>
using namespace std;

int teskes, n; 
long long maks[120000], mins[120000];
int main() {
    
    scanf("%d", &n);
    while(n!=0) {
        long long ans = 0;
        for(int i=0; i<n; i++) {
            int num;
            scanf("%d", &num);
            if(num > 0) {
                if(i==0) mins[i]=0,maks[i]=num;
                else mins[i]=mins[i-1],maks[i]=maks[i-1]+num;
            } else {
                if(i==0) mins[i]=num,maks[i]=0;
                else mins[i]=mins[i-1]+num,maks[i]=maks[i-1];
            }
        }
        for(int i=0; i<n; i++) ans+=abs(maks[i]+mins[i]);
        printf("%lld\n", ans);
        scanf("%d", &n);
    }
    return 0;
}

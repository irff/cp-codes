#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

typedef long long LLD;
typedef pair<LLD, LLD> PLL;

LLD n, permen[102000];
PLL bebek[102000];

int main() {
    scanf("%lld", &n);
    
    LLD awal = 1000000000000LL;;
    LLD akhir = -1000000000000LL;
    LLD mid = 500000000000LL;
    
    for(int i=0; i<n; i++) {
        scanf("%lld%lld", &bebek[i].first, &bebek[i].second);
        awal = min(awal, bebek[i].second);
        akhir = max(akhir, bebek[i].second);
    }
    sort(bebek, bebek+n);

    while(awal != akhir) {
        for(int i=0; i<n; i++) permen[i] = bebek[i].second;
        for(int i=0; i<n-1; i++) {
            if(permen[i] > mid) {
                LLD x = permen[i]-mid;
                if(permen[i+1] + (x-(bebek[i+1].first-bebek[i].first)) >= permen[i+1])
                  permen[i+1] += (x-(bebek[i+1].first-bebek[i].first));
            } else if(permen[i] < mid) {
                LLD x = mid - permen[i];
                permen[i+1] = permen[i+1] - (x + (bebek[i+1].first-bebek[i].first));
            }
        }
        if(permen[n-1] < mid) {
            akhir = mid-1;
        } else if(permen[n-1] >= mid) {
            awal = mid;
        }
        mid = (awal+akhir)/2+1;
        //printf("%lld %lld %lld\n", awal, akhir, mid);
    }
    printf("%lld\n", awal);
    
    return 0;
}

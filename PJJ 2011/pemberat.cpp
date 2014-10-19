#include <algorithm>
#include <cstdio>
using namespace std;


long long a,b,pangkat[63],selisih;
int main() {
    scanf("%lld%lld", &a, &b);
    selisih = b-a;
    
    pangkat[0] = 1;
    for(long long i=1; i<63; i++) {
        pangkat[i] = pangkat[i-1] * 2;
    }
    for(int i = 62; i>=0; i--) {
        if(selisih >= pangkat[i]) printf("%lld\n", pangkat[i]), selisih-=pangkat[i];
    }
        
    return 0;
}

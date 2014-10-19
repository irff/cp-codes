#include <cstdio>
#include <algorithm>
using namespace std;

long long n,cc[12000];;
int coin[5] = {1,5,10,25,50};
int main() {
    cc[0]=1;
    for(int i=0; i<5; i++) {
        for(int j=1; j<=10000; j++) {
            if(j-coin[i] >=0) cc[j] += cc[j-coin[i]];
        }
    }
    while(scanf("%d", &n) > 0) {
       printf("%lld\n", cc[n]);
    }

    return 0;
}

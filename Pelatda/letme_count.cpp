#include <cstdio>
#include <algorithm>
using namespace std;

long long n,cc[35000];;
int coin[5] = {1,5,10,25,50};
int main() {
    cc[0]=1;
    for(int i=0; i<5; i++) {
        for(int j=1; j<=35000; j++) {
            if(j-coin[i] >=0) cc[j] += cc[j-coin[i]];
        }
    }
    while(scanf("%lld", &n) > 0) {
       if(cc[n]==1) {
         printf("There is only 1 way to produce %lld cents change.\n", n);
       } else printf("There are %lld ways to produce %lld cents change.\n", cc[n], n);
    }

    return 0;
}

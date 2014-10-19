#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)


long long n, sum=0, maks=-2000111222, a;
int main() {
    scanf("%lld", &n);
    R(i,0,n) {
        scanf("%lld", &a);
        maks=max(maks,a);
        if(sum+a>=0){
            sum+=a;
            maks=max(sum,maks);
        } else {
            sum = 0;
        }
    }
    printf("%lld\n", maks);

    return 0;
}

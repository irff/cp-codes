#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LLD;
LLD num,ans[300];
int ctr = 0;
int main() {
    scanf("%lld", &num);
    for(long long i=1; i*i<=num; i++) {
        if(num%i==0) {
            ans[ctr] = i;
            ctr++;
            LLD x = i*i;
            if((LLD)i*i!=num) { ans[ctr] = (LLD)num/i; ctr++; }
        }
    }
    sort(ans, ans+ctr);
    printf("%d\n", ctr);
    for(int i=0; i<ctr; i++) printf("%lld\n", ans[i]);
    return 0;
}

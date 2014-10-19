#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef long long LLD;

LLD y, k, n;
int main() {
    scanf("%lld%lld%lld", &y, &k, &n);
    bool ada = 0;
    for(int i=1; i*k<=n; i++) {
        if(i*k-y>0) {
            if(ada) printf(" ");
            else ada = 1;
            printf("%lld", i*k-y);
        }
    }
    if(!ada) printf("-1\n");
    return 0;
}

#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a); i<int(_b); i++)

int teskes, n;
long long a[2000111];
int main() {
    R(i,1,1500111) {
        a[i] = a[i-1];
        if(i%4 == 0 or i%7 == 0) a[i] += i;
    }
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%d", &n);
        printf("%lld\n", a[n]);
    }
    return 0;
}

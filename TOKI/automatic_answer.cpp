#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int t, n;
int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        n*=567;
        n/=9;
        n+=7492;
        n*=235;
        n/=47;
        n-=498;
        n%=100;
        n/=10;
        printf("%d\n", n<0?-n:n);
    }
    return 0;
}

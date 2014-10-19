#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n, q, a[52000], num;
int main() {
    scanf("%d%d", &n, &q);
    R(i,0,n) { scanf("%d", &a[i]); if(i>0) a[i]=a[i-1]+a[i]; }
    R(i,0,q) {
        scanf("%d", &num);
        printf("%d\n", upper_bound(a,a+n,num)-&a[0]+1);
    }
    return 0;
}

#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef long long LLD;

LLD x[100111], v[100111], ans[100111];
int n, a[100111];

int main() {
    scanf("%d", &n);
    R(i,0,n) scanf("%d", &a[i]);
    
    LLD total = 0;
    int now = 0, size = 0;
    
    R(i,0,n) {
        now = size;
        int sum = 1;
        while(now > 0 and x[now-1] <= a[i]) {
            now--;
            sum += v[now];
        }
        if(now == size) {
            x[size] = a[i];
            v[size] = 1;
            size++;
        } else {
            v[now] = sum;
            x[now] = a[i];
            size = now+1;
        }
        total += sum;
        ans[i] = sum;
    }
    /*
    R(i,0,n) printf("%d ", ans[i]);
    printf("\n");
    */
    printf("%lld\n", total);
    return 0;
}

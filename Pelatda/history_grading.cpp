#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n, a[30], x[30], lis[30];
int main() {
    scanf("%d", &n);
    R(i,0,n) {
        int num; scanf("%d", &num);
        a[num-1] = i;
    }
    int ctr = 0, num, ans = 0;
    while(scanf("%d", &num) > 0) {
        x[ctr] = a[num-1];
        ctr++;
        if(ctr >= n) {
            ans = 1;
            R(i,0,n) {
                R(j,0,i) {
                    if(x[i] > x[j]) lis[i] = max(lis[i], lis[j]+1);
                }
                ans = max(ans, lis[i]);
            }
            printf("%d\n", ans);
            ctr = 0;
            R(i,0,n) lis[i] = 1;
        }
    }
    return 0;
}

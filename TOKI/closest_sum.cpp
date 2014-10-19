#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n, q, kasus = 0;
int a[1200];
int main() {
    while(scanf("%d", &n), n) {
        kasus++;
        vector<int> v;
        R(i,0,n) scanf("%d", &a[i]);
        R(i,0,n) {
            R(j,i+1,n) {
                v.push_back(a[i]+a[j]);
            }
        }
        sort(v.begin(), v.end());
        vector<int>::iterator it = unique(v.begin(), v.end());
        int x = it-v.begin();
        scanf("%d", &q);
        printf("Case %d:\n", kasus);
        R(i,0,q) {   
            int x; scanf("%d", &x);
            vector<int>::iterator ans = lower_bound(v.begin(), it, x);
            printf("Closest sum to %d is ", x);
            //printf("%d %d\n", *(ans-1), *ans);
            if(ans == v.begin()) {
                printf("%d.\n", *ans);
            } else {
                if( abs(*(ans) - x) < abs(*(ans-1) - x)) {
                    printf("%d.\n", *ans);
                } else printf("%d.\n", *(ans-1));
            }
        }
    }
    return 0;
}

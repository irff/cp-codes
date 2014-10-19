#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define pb(x) push_back(x);


int teskes, n, kasus = 0;
vector<int> h, w;
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%d", &n);
        int num;
        h.clear(), w.clear();
        R(i,0,n) { scanf("%d", &num); h.pb(num); }
        R(i,0,n) { scanf("%d", &num); w.pb(num); }
        vector<int> lis(n,0), lds(n,0);
        int maks_lis = 0, maks_lds = 0;
        R(i,0,n) {
            //printf("%d %d\n", h[i], w[i]);
            lis[i] = w[i], lds[i] = w[i];
            R(j,0,i) {
                if(h[i] > h[j]) {
                    lis[i] = max(lis[i], lis[j]+w[i]);
                }
                if(h[i] < h[j]) {
                    lds[i] = max(lds[i], lds[j]+w[i]);
                }
            }
            maks_lis = max(maks_lis, lis[i]);
            maks_lds = max(maks_lds, lds[i]);
        }
        printf("Case %d. ", ++kasus);
        if(maks_lis>=maks_lds) {
            printf("Increasing (%d). Decreasing (%d).\n", maks_lis, maks_lds);
        } else printf("Decreasing (%d). Increasing (%d).\n", maks_lds, maks_lis);
    }
    return 0;
}

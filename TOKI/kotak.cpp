#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n, a[100], b[100];
int ans = 0, memo[100], id = 0;

vector<int> v;

int rek(int ke) {
    if(memo[ke]>0) return memo[ke];
    int maks = 0;
    
    R(i,0,n) {
        if(a[i] < a[ke] and b[i] < b[ke] or b[i] < a[ke] and a[i] < b[ke]) {
            maks = max(maks, rek(i)+1);
        }
    }
    
    return memo[ke] = maks;
}

int main() {
    scanf("%d", &n);
    R(i,0,n) scanf("%d%d", &a[i], &b[i]);
    
    R(i,0,n) {
        int now = rek(i)+1;
        if(ans < now) {
            ans = now;
            id = i;
        }
    }
    
    printf("%d\n", ans);
    int uk = ans;
    ans--;
    while( ans > 0) {
        v.push_back(id+1);
        R(i,0,n) {
            if(memo[i] == ans-1 and ( (a[id] > a[i] and b[id] > b[i]) or (a[id] > b[i] and b[id] > a[i]) )) {
                //printf("x");
                ans--;
                id = i;
                break;
            }
        }
    }
    v.push_back(id+1);
    reverse(v.begin(), v.end());
    
    R(i,0,v.size()) {
        printf("%d ", v[i]);
    }
    printf("\n");
    return 0;
}

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n, len, dist = 0;
typedef vector<int> VI;
vector<int> a;

VI skew(VI a, int awal, int akhir) {
    int sel = (akhir-awal)/2;
    
    int mid = (awal+akhir)/2;
    VI va; va.assign(a.begin(), a.begin()+sel);
    VI vb; vb.assign(a.begin()+sel, a.end());
    
    if(sel > 1) {
        va = skew(va, awal, mid);
        vb = skew(vb, mid, akhir);
    }
    if(va > vb) {
        dist +=(2*sel*sel);
        vb.insert(vb.end(), va.begin(), va.end());
        return vb;
    }
    va.insert(va.end(), vb.begin(), vb.end());
    return va;
    
}

int main() {
    scanf("%d", &n);
    len = (1<<n);
    R(i,0,len) {
        int num;
        scanf("%d", &num);
        a.push_back(num);
    }
    vector<int> ans = skew(a,0,len);
    printf("%d\n", dist);
    R(i,0,len) printf("%d\n", ans[i]);
    return 0;
}

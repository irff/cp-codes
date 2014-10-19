#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int num, n, a[15];
set< vector<int> > vis;
void rek(int ke, int sisa, vector<int> v) {
    if(sisa==0) {
        if(vis.find(v)!=vis.end()) return ;
        vis.insert(v);
        int len = v.size();
        printf("%d", v[0]);
        R(i,1,len) {
            printf("+%d", v[i]);
        }
        printf("\n");
        return ;
    }
    
    if(ke>=n) return ;
    
    if(sisa-a[ke] >= 0) {
        v.push_back(a[ke]);
        rek(ke+1, sisa-a[ke], v);
        v.pop_back();
    }
    rek(ke+1, sisa, v);
    return ;
}

int main() {
    while( scanf("%d%d", &num, &n) and n!=0 ){
        R(i,0,n) scanf("%d", &a[i]);
        vis.clear();
        printf("Sums of %d:\n", num);
        vector<int> v;
        rek(0, num, v);
        if(vis.empty()) printf("NONE\n");
    }
    return 0;
}

#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a); i<int(_b); i++)

const int INF = 2000111222;

int m[120000], t[250000], kiri, kanan, n, q;

void buildtree(int now, int a, int b) {
    if(a==b) t[now] = m[a];
    else {
        buildtree(now*2+1, a, (a+b)/2);
        buildtree(now*2+2, (a+b)/2+1, b);
        t[now] = max(t[now*2+1],t[now*2+2]);
    }
}

int query(int now, int a, int b) {
    //out of range
    if(kiri > b or kanan < a) return -INF;
    //in range
    if(a >= kiri and b <= kanan) {
        return t[now];
    }
    //intersection    
    int ki = query(now*2+1, a, (a+b)/2);
    int ka = query(now*2+2, (a+b)/2+1, b);
    return max(ki, ka);
    
}

int main() {
    scanf("%d", &n);
    R(i,0,n) scanf("%d", &m[i]);
    buildtree(0,0,n-1);
    R(i,0,n*2+3) printf("%d %d\n", i, t[i]);
    scanf("%d", &q);
    R(i,0,q) {
        scanf("%d%d", &kiri, &kanan);
        kiri--; kanan--;
        printf("%d\n", query(0,0,n-1));
    }
    return 0;
}

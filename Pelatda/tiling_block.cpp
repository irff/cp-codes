#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef struct {
    int a, b;
} block;

int n;
block x[120000], m[120000];

bool cp(block f, block s) {
    if(f.a == s.a) {
        return f.b > s.b;
    }
    return f.a > s.a;
}

int main() {
    scanf("%d", &n);
    while(n) {
        R(i,0,n) {
            scanf("%d%d", &x[i].a, &x[i].b);
        }
        sort(x, x+n, cp);
        int now = 0, size = 1;
        m[0].a = -
        R(i,0,n) {
        
        }
        scanf("%d", &n);
    }

    return 0;
}

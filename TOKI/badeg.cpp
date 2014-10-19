#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int s, n, t, x;
bool bisa = 1;
map<int,bool> m;
int main() {
    scanf("%d%d", &s, &n);
    R(i,0,n) {
        scanf("%d%d", &t, &x);
        if(t<x) bisa = 0;
        else {
            m[x-t] = 1;
        }
    }
    if(bisa) {
        printf("%d\n", m.size());
    } else printf("CIYUS IMPOSSIBRU\n");
    return 0;
}

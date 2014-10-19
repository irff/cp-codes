#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

typedef pair<double,int> DI;
DI x[1200];
int teskes, n;

bool cp(DI a, DI b) {
    if(fabs(a.first-b.first) < 1e-9) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

int main() {
    scanf("%d", &teskes);
    for(int k=0; k<teskes; k++) {
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            int a,b; scanf("%d%d", &a, &b);
            x[i].second = i;
            x[i].first  = (double)b/a;
        }
        sort(x,x+n,cp);
        for(int i=0; i<n; i++) printf("%d%c", x[i].second+1, i==n-1?'\n':' ');
        if(k!=teskes-1) printf("\n");
    }
    return 0;
}

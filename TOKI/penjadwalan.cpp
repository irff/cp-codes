#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef struct {
    int p, d;
} task;

typedef long long LLD;

task x[210000];
int n;
LLD ans = 0;

bool cp(task a, task b) {
    if(a.d == b.d) {
        return a.p > b.p;
    }
    return a.d > b.d;
}

int main() {
    scanf("%d", &n);
    R(i,0,n) {
        scanf("%d%d", &x[i].p, &x[i].d);
    }
    sort(x, x+n, cp);
    //R(i,0,n) printf("%d %d\n", x[i].p, x[i].d);
    
    int now = 0, maks = x[now].d;
    while( maks > 0 and now < n) {
        //printf("%d %d\n", now, maks);
        if(x[now].d==maks) {
            ans+=x[now].p;
            now++;
            int tmp = x[now].p, id = now, ctr = now;
            while(x[ctr].d == maks) {
                if(x[ctr].p > tmp) {
                    id = ctr;
                    tmp = x[ctr].p;
                }
                x[ctr].d--;
                ctr++;
            }
            if(x[ctr].p > tmp) {
                id = ctr;
                tmp = x[ctr].p;
            }
            if(tmp > x[now].p) {
                swap(x[now], x[id]);
            }
            maks--;
        } else maks--;
    }
    printf("%lld\n", ans);
    return 0;
}

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

typedef struct {
    int iq, w, id;
} gajah;

gajah a[1200];
int teskes, p[1200], lis[1200], n = 0, final[1200];

bool cp(gajah a, gajah b) {
    return a.iq >= b.iq;
}

int main() {
    while(scanf("%d%d", &a[n].w, &a[n].iq) > 0) {
        a[n].id = n+1;
        n++;
    }
    sort(a, a+n, cp);
    R(i,0,n+3) {
        lis[i] = 1;
        p[i] = -1;
    }
    int maks = 0, idx = 0;
    R(i,0,n) {
        R(j,0,i) {
            if(a[i].w > a[j].w and lis[i] < lis[j]+1) {
                lis[i] = lis[j]+1;
                p[i] = j;
            }
        }
        if(lis[i] > maks) {
            maks = lis[i];
            idx = i;
        }
    }
    int uk = 0;
    while(p[idx]!=-1) {
        final[uk++] = a[idx].id;
        idx = p[idx];
    }
    
    final[uk++] = a[idx].id;
    printf("%d\n", uk);
    RV(i,uk-1,0) {
        printf("%d\n", final[i]);
    }
    return 0;
}

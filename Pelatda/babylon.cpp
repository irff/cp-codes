#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef struct {
    int a, b, c;
} cube;

cube x[1000111];
int lis[100111], n;

bool cp(cube f, cube s) {
    if(f.a==s.a) {
        return f.b < s.b;
    }
    return f.a < s.a;
}

int main() {
    scanf("%d", &n);
    while(n) {
        int ctr = 0;
        int ans = 0;
        R(i,0,n) {
            int va, vb, vc; scanf("%d%d%d", &va, &vb, &vc);
            x[ctr].a = va, x[ctr].b = vb, x[ctr].c = vc; ctr++;
            x[ctr].a = va, x[ctr].b = vc, x[ctr].c = vb; ctr++;
            
            x[ctr].a = vb, x[ctr].b = va, x[ctr].c = vc; ctr++;
            x[ctr].a = vb, x[ctr].b = vc, x[ctr].c = va; ctr++;
            
            x[ctr].a = vc, x[ctr].b = va, x[ctr].c = vb; ctr++;
            x[ctr].a = vc, x[ctr].b = vb, x[ctr].c = va; ctr++;
        }
        sort(x, x+ctr, cp);
        R(i,0,ctr) {
            lis[i] = x[i].c;
            R(j,0,i) {
                if(x[i].a > x[j].a and x[i].b > x[j].b) {
                    lis[i] = max(lis[i], lis[j]+x[i].c);
                }
            }
            ans = max(ans, lis[i]);
            //printf("%d %d %d - %d\n", x[i].a, x[i].b, x[i].c, lis[i]);
        }
        printf("%d\n", ans);
        scanf("%d", &n);
    }

    return 0;
}

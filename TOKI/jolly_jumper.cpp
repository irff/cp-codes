#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n, a[4000];
bool m[4000];
int main() {
    while( scanf("%d", &n) > 0) {
        memset(m, 0, sizeof m);
        R(i,0,n) {
            scanf("%d", &a[i]);
            if(i>0) {
                m[abs(a[i]-a[i-1])] = 1;
            }
        }
        bool jolly = 1;
        R(i,1,n) if(!m[i]) { jolly = 0; break; }
        if(jolly) printf("Jolly\n");
        else printf("Not jolly\n");
    }

    return 0;
}

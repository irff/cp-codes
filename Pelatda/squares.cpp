#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

const int INF = 2000111222;

int teskes, n;
int a[10111]; 
int main() {
    R(i,0,10111) a[i] = INF;
    a[0] = 0;
    R(i,1,101) {
        R(j,1,10111) {
            if(j-i*i>=0) {
                a[j] = min(a[j], a[j-i*i]+1);
            }
        }
    }
    scanf("%d", &teskes);
    while(teskes--) {       
        scanf("%d", &n);
        printf("%d\n", a[n]);
    }
    return 0;
}

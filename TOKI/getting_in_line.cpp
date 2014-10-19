#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n, cx[10], cy[10];
double dist[10][10], ans = 0.00;

double rek(int pos, int b) {
    bool bisa = 0;
    R(i,0,n) if(!(b&(1<<i))) bisa = 1;
    if(!bisa) return 0;
    
    double ans = 1000000000;
    R(i,0,n) {
        if(!(b&(1<<i))) {
            ans = min(ans, rek(i,b|(1<<i))+dist[pos][i]);
        }
    }
    printf("%.2lf\n", ans);
    return ans;
}

int main() {
    while(scanf("%d", &n), n) {
        R(i,0,n) {
            scanf("%d%d", &cx[i], &cy[i]);
        }
        R(i,0,n) {
            R(j,0,n) {
                dist[i][j] = sqrt( (double)(cx[i]-cx[j])*(cx[i]-cx[j])+(cy[i]-cy[j])*(cy[i]-cy[j]));
            }
        }
        ans = 1000000000;
        R(i,0,n) ans = min(ans,rek(i, (1<<i)));
        printf("%.2lf\n", ans);
    }
    
    return 0;
}

#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int x[400],y[400], n;
long long mins = 2000111222333LL;
int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d%d", &x[i], &y[i]);
    bool dup=0;
    for(int i=0; i<n; i++)
      for(int j=i+1; j<n; j++)
        for(int k=j+1; j<n; j++) {
            long long luas = (long long)labs( x[i]*(y[j]-y[k])+x[j]*(y[k]-y[i])+x[k]*(y[i]-y[j]) );
            if(luas!=0) {
                if(mins == luas) dup=1;
                else if(mins > luas) mins = luas;
            }
        }
    if(mins==2000111222333LL or dup) printf("-1.00\n");
    else {
        printf("%.2lf\n", (double)mins/2);
    }
    return 0;
}

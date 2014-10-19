#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define x first
#define y second
pair<int,int> a[400];
int n;
 
long long mins = 2000111222;
 
int main() {
     
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d%d", &a[i].first, &a[i].second);
    bool dupl = 0;
    int ai,aj,ak;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            for(int k=j+1; k<n; k++) {
                long long luas = (long long)labs( (a[i].x*a[j].y+a[j].x*a[k].y+a[k].x*a[i].y)-(a[j].x*a[i].y+a[k].x*a[j].y+a[i].x*a[k].y));
                if(luas!=0) {
                    if(mins > luas) {
                        ai=i,aj=j,ak=k;
                        mins = luas;
                    }
                }
            }
        }
    }
        for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            for(int k=j+1; k<n; k++) {
                long long luas = (long long)labs( (a[i].x*a[j].y+a[j].x*a[k].y+a[k].x*a[i].y)-(a[j].x*a[i].y+a[k].x*a[j].y+a[i].x*a[k].y));
                if(luas!=0) {
                    if(mins==luas and not(ai==i and aj==j and ak==k)) dupl=1;
                }
            }
        }
    }
    //printf("%f\n", mins);
    if(mins == 2000111222 or dupl) {
        printf("-1.00\n");
    } else printf("%.2lf\n", (double)mins/2 );
    return 0;
}

#include <cstdio>
#include <algorithm>
#include <valarray>
using namespace std;
#define PII pair<int,int>
#define x first
#define y second
PII a[1000];
int kap,n;
int main(){
    valarray<double> va(1000);
    scanf("%d %d", &kap, &n);
    for(int i=0; i<n; i++){
        scanf("%d%d", &a[i].y, &a[i].x);
    }
    sort(a,a+n);
    int hasil=0;
    int maks=-1;
    int ct=0;
    int berat=a[ct].x;
    maks=a[ct].y;
    while(ct!=n){
        maks=a[ct].y;
        while(berat+a[ct+1].y<=kap){
            berat+=a[ct+1].y;
            ct++;
            maks=max(maks,a[ct].y);
        }
        hasil+=maks;
        berat=0;
        ct++;
    }
    printf("%d\n", hasil);
    scanf("\n");
    return 0;
}

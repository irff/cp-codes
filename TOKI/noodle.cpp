#include <cstdio>
#include <algorithm>
using namespace std;
#define PII pair<int,int>

int teskes,n,maks;
PII a[13];
int main(){
    scanf("%d", &teskes);
    while(teskes--){
        scanf("%d", &n);
        for(int i=0; i<n; i++) { scanf("%d%d", &a[i].second, &a[i].first); a[i].first*=-1; }
        sort(a,a+n);
        for(int i=0; i<n; i++) a[i].first*=-1;
        maks=a[0].first + a[0].second;
        for(int i=1; i<n; i++){
            a[i].second+=a[i-1].second;
            maks=max(maks,a[i].first+a[i].second);
        }
        printf("%d\n", maks);
    }
    return 0;
}

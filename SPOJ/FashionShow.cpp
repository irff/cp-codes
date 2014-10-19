#include <cstdio>
#include <algorithm>
using namespace std;

int teskes,n,a[2000],b[2000];
int main(){
    scanf("%d",&teskes);
    while(teskes--){
        long long sum=0;
        scanf("%d",&n);
        for(int i=0; i<n; i++) scanf("%d", &a[i]);
        for(int i=0; i<n; i++) scanf("%d", &b[i]);
        sort(a,a+n); sort(b,b+n);
        for(int i=0; i<n; i++) sum+=(a[i]*b[i]);
        printf("%lld\n", sum);
    }

}

#include <cstdio>

long long a,n,sum[110000],MAX,NEG;
int main(){
    scanf("%lld", &n);
    for(int i=1; i<=n; i++){
        scanf("%lld", &a);
        if(sum[i-1]+a>0){
            sum[i]=sum[i-1]+a;
        }
        else sum[i]=0;
    }
    for(int i=1; i<=n; i++) if(sum[i]>MAX) MAX=sum[i];
    printf("%lld\n", MAX);
    scanf("\n");
    return 0;
}

#include <cstdio>

long long teskes,n;
long long jum,rat,num;
int main(){
    scanf("%lld",&teskes);
    while(teskes--){
        jum=0;
        scanf("%lld", &n);
        if(n==0) printf("YES\n");
        else{ for(int i=0; i<n; i++) scanf("%lld", &num),jum+=num;
              rat=jum/n;
              if(rat*n==jum) printf("YES\n");
              else printf("NO\n");
        }
    }
    return 0;
}

#include <cstdio>

typedef long long LLD;

LLD a,b;
int main(){
    scanf("%lld%lld", &a,&b);
    int even=0;
    for(LLD i=1; i<=a; i++){
        LLD n=i;
        LLD sum=0;
        while(n!=0){
            sum+=n%10;
            n/=10;
        }
        if(sum%2==0) even++;
        //printf("%I64d %I64d\n", i, sum);
        printf("%I64d %d\n", i, even);
    }
    printf("even = %d\n", even);
    scanf("\n");

}

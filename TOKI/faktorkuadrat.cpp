#include <cstdio>
#include <iostream>
#include <bitset>
#include <algorithm>
using namespace std;

bitset<1000001> bs;
long long n,punk,hasil;
int main(){
    hasil=1;
    bs.set();
    for(int i=2; i*i<=50000; i++){
        long long j=2*i;
        while(j<=50000){
            bs[j]=0;
            j+=i;
        }
    }
    scanf("%lld", &n);
    for(long long i=2; i<=n; i++){
        punk=0;
        if(bs[i]) {
            long long tmp=i;
            while(tmp<=n){
                punk+=(n/tmp);
                tmp*=i;
            }
        }
        hasil=hasil*((punk/2)+1)%1000000009LL;
    }
    printf("%lld\n", hasil);
    return 0;
}

#include <cstdio>
using namespace std;

long long n;
int hasil;
int teskes;
int a[200];
long long pangkat(long long a,long long b){
     if(b==0) return 1;
     long long tmp=pangkat(a,b/2)%10;
     if(b%2) return (a*tmp)%10*tmp%10;
     return tmp*tmp%10;
}
int main(){
    scanf("%d", &teskes);
    for(long long i=1; i<=100; i++){
            hasil=(hasil%10+pangkat(i,i)%10)%10;
            a[i]=hasil;
        }
    while(teskes--){
        scanf("%lld", &n);
        printf("%d\n", a[n%100]);
    }
    return 0;
}

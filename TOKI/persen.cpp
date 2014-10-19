#include <cstdio>
using namespace std;
#define ll long long
int a,b,c,d;
ll hasil;
ll pangkat(ll a, ll b, ll n){
    if(b==0) return 1;
    ll tmp=pangkat(a,b/2,n)%n;
    if(b%2) return a*tmp*tmp%n;
    else return tmp*tmp%n;
}
int main(){
    scanf("%d%d%d%d", &a,&b,&c,&d); hasil=b;
    for(int i=0; i<d; i++) hasil=pangkat(hasil,c,100)%100;
    hasil=pangkat(a,hasil,101)%101;
    printf("%lld\n", hasil);
    return 0;
}

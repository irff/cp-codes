#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
 
int x;
long long n;
int main(){
    scanf("%lld", &x);
    n=1;
    int hasil=1,lima=0,dua=0;
    for(int i=1; i<=x; i++){
        n=i;
        while(n%2==0) n/=2,dua++;
        while(n%5==0) n/=5,lima++;
        hasil=((hasil%10)*(n%10))%10;
    }
    int a=dua-lima;
    for(int i=0; i<a; i++)
        hasil=(hasil*2)%10;
    printf("%lld\n", hasil);
    scanf("\n");
    return 0;
}

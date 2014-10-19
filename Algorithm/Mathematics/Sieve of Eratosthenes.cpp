#include <cstdio>
#include <bitset>
using namespace std;

bitset<1000000> bs;
int n;
int main(){
    scanf("%d", &n); // input the maximum value
    // the sieve
    bs.set(); bs[0]=0; bs[1]=0;
    for(int i=2;i*i<=n;i++) for(int j=i*i;j<=n; j+=i) bs[j]=0;
    
    // checking . . .
    while(scanf("%d", &n)>0) printf("%d\n", bs.test(n));
    scanf("\n");
    return 0;
}

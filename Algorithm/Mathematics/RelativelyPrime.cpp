#include <cstdio>
#include <bitset>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LLD;
 
LLD n;
bitset<1000001> bs;
vector<int> p;
int main(){
    bs.set(); bs[0]=0; bs[1]=0;
    for(int i=2; i*i<=1000000; i++){
        for(int j=i*i; j<=1000000; j+=i) bs[j]=0;
    }
    for(int i=3; i<=1000000; i++) if(bs[i]) p.push_back(i);
    scanf("%lld", &n);
    LLD result=n;
    if(n%2==0) result-=result/2;
    while(n%2==0) n/=2;
    for(vector<int>::iterator it=p.begin(); *it**it<=n and it!=p.end(); it++){
        int i=*it;
        if(n%i==0) result-=result/i;
        while(n%i==0) n/=i;
    }
    if( n > 1 ) result-=(LLD)(double)result/n;
    printf("%lld\n", result);
    scanf("\n");
}

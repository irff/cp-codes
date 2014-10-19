#include <cstdio>
#include <vector>
#include <bitset>
using namespace std;

int a,b,mi,ma,np;
long long hasil;
vector<int> prim;
bitset<1000500> bs;
int main(){
    bs.set(); bs[0]=0;bs[1]=0;
    for(int i=2; i*i<=1000000; i++)
        for(int j=i*i; j<=1000000; j+=i) bs[j]=0;
    for(int i=2; i<=1000000; i++)
        if(bs[i]) prim.push_back(i);
    scanf("%d%d", &a, &b);
    for(int i=0; i<=a; i++) if(bs[i]) np++;
    if(np>=b){
        for(int i=0; i<np-b+1; i++){
            if(i==0) mi=1;
            else mi=prim[i]-prim[i-1];
            ma=prim[i+b-1];       
            hasil+=mi*(a-ma+1);
        }
        printf("%lld\n", hasil);
    }
    else puts("0");
    return 0;
}

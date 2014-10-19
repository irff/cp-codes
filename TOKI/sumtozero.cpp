#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int teskes, n;
long long na[2000],nb[2000],nc[2000];

int main(){
    scanf("%d", &teskes);
    while(teskes--){
        scanf("%d", &n);
        R(i,0,n) scanf("%lld", &na[i]);
        R(i,0,n) scanf("%lld", &nb[i]); sort(nb,nb+n);
        R(i,0,n) scanf("%lld", &nc[i]); sort(nc,nc+n);
        
        long long hasil=0;
        R(i,0,n){
            long long x=-na[i];
            long long b=0,c=n-1;
            while(b<n and c>=0){
                long long jumb=1;
                while(b+1<n and nb[b]==nb[b+1]) b++,jumb++;
                while(c>=0  and nb[b]+nc[c]>x) c--;
                if(c<0) break;
                if(nb[b]+nc[c]==x){
                    int jumc = 1;
                    while(c>0 and nc[c]==nc[c-1]) c--,jumc++;
                    hasil+=jumb*jumc;
                }
                b++;
            }
        }
        printf("%lld\n", hasil);
    
    }    
    return 0;
}

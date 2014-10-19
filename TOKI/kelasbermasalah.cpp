#include <cstdio>
#include <algorithm>
using namespace std;

double a[100000];
long teskes,n,sampah;
double rata,jum;
int main(){
    scanf("%ld", &teskes);
    while(teskes--){
        jum=0.0; rata=0.0; sampah=0;
        scanf("%ld", &n);
        for(int i=0; i<n; i++) { scanf("%lf", &a[i]); jum+=a[i]; }
        rata=jum/n;
        for(int i=0; i<n; i++) if(a[i]<rata) sampah++;
        printf("%ld\n", sampah);
    }
    return 0;
}

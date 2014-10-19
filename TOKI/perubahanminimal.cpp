#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

long minz;
int teskes,n,a[10000];
int main(){
    scanf("%d", &teskes);
    while(teskes--){
        minz=0;
        scanf("%d", &n);
        R(i,0,n) scanf("%d", &a[i]);
        sort(a,a+n);
        R(i,0,n) minz+=abs(a[i]-(i+1));
        printf("%ld\n", minz);
    }
    return 0;
}

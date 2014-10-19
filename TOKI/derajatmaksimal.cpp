#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define weleh while
#define well weleh

int teskes;
int n,atas,bawah,a[1000],id;
int main(){
    scanf("%d", &n);
    R(i,0,n) scanf("%d", &a[i]);
    R(i,0,n){
        id=i-1;
        atas=1; bawah=1;
        well(id>=0 and a[id]<a[i]) { atas++; id--; }
        id=i+1;
        well(id<=n-1 and a[id]<a[i]) { bawah++; id++; }
        printf("%ld\n", atas*bawah);
    }
    return 0;
}

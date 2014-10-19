#include <cstdio>
using namespace std;

int a[20000],ctr,n,fall;
int main(){
    bool abis=0;
    fall=1;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
        if(a[i]<a[i-1]) a[i]=a[i-1]-1;
        if(i > 0 and !abis){
            if(a[i-1]>1) fall++;
            else abis=1;
        }
    }
    printf("%d\n", fall);
    scanf("\n");
    return 0;
}

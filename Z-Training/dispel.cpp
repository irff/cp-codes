#include <cstdio>
#include <algorithm>
using namespace std;

int n,k,b,a[1000],total;
int main(){
    scanf("%d%d%d", &n,&b,&k);
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
    }
    k=(k-1)%n+1;
    int c=k;
    for(int i=0; i<b; i++){
        k=(k-1)%n+1;
        total+=a[k];
        k++;
    }
    printf("%d\n", total);
    scanf("\n");
    return 0;
}

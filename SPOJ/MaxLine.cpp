#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
    int teskes,n;
    scanf("%d",&teskes);
    for(int i=1; i<=teskes; i++){
        scanf("%d", &n);
        float x=4*n*n+0.25;
        printf("Case %d: %.2f\n", i,x);
    }
    scanf("\n");
    return 0;
}

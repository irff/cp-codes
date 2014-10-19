#include <cstdio>
#include <cmath>
int main(){
    int n;scanf("%d", &n);
    while(n){
        printf("%.2lf\n", (n*n)/acos(-1)/2);
        scanf("%d", &n);
    }
}

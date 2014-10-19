#include <cstdio>


int n,a,b;
int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a);
        b+=a;
    }
    printf("%d\n", b);
}

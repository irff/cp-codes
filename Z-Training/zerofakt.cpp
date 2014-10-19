#include <cstdio>

int n,digit;
int main(){
    scanf("%d", &n);
    while(n!=0){
        digit+=n/5;
        n/=5;
    }
    printf("%d\n", digit);
    scanf("\n");
    return 0;
}

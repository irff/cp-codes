#include <cstdio>

int n,k,num,t;
int main(){
    scanf("%d%d", &n,&k);
    while(n--){
        scanf("%d", &num);
        if(num%k==0) t++;
    }
    printf("%d\n", t);

    return 0;
}

#include <cstdio>

int low,num;
int main() {
    scanf("%d%d", &low, &num);
    for(int i=low+1; ; i++) {
        int x=i,sum=0;
        while(x>0) {
            sum+=(x%10);
            x/=10;
        }
        if(sum==num) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}

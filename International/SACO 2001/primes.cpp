#include <cstdio>

int num,n,x=2;
int main() {
    scanf("%d", &num);
    n=num;
    printf("%d = ", num);
    while(n>1) {
        while(n%x==0) {
            if(n!=num and n!=1) printf("x ");
            printf("%d%c", x,(n==x)?'\n':' ');
            n/=x;
        }
        x++;
    }
    return 0;
}

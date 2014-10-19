#include <cstdio>

int i,x,dapet,sisa;
int main() {
        scanf("%d", &i);
        int x=i;    
        dapet=x;
        while(x>=3) {
            sisa=x%3;
            x/=3;
            dapet+=x;
            x+=sisa;
        }
        printf("%d\n", dapet);
}

#include <cstdio>
#include <cmath>

int teskes,x,hasil;
int main () {
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%d", &x);
        x-=4;
        if(x<0) printf("-1\n");
        else {
            int n=sqrt(2*(x));
            for(int i=n-1; i<n+2; i++)
                if( (i*(i+1)/2)>x) {
                    hasil=i-1;
                    break;
                }
            printf("%d\n", hasil);
        }
    }
    return 0;
}

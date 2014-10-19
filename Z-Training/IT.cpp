#include <cstdio>

double m,b,x,y;
int n,hasil;
int main(){
    scanf("%lf%lf", &m,&b);
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%lf%lf", &x,&y);
        if(m*x+b==y and m*x+b>=0 and y>=0 and x>=0) {  hasil++; }
    }
    printf("%d\n", hasil);
    return 0;
}

#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;

int n;
int main(){
    scanf("%d", &n);
    int x=9, d=1, tmp=0;
    while(n>=x*d){
        n-=(x*d);
        tmp+=(x*d);
        //printf("%d %d\n", x,d);
        x*=10;
        d++;
    }
    int nth=ceil((double)n/d);
    //printf("%d %d %d\n", n, d, nth);
    int digit=n%d;
    nth+=tmp;
    digit=d-digit;
    int c=0;
    printf("%d\n", nth);
    printf("%d\n", digit);
    for(int i=0; i<digit; i++){
        c=nth%10;
        nth/=10;
    }
    printf("%d\n", c);
    scanf("\n");

    return 0;
}

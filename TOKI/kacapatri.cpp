#include <cstdio>
#include <cmath>
using namespace std;

long l,p;
double x,pi;
int teskes;
int main(){
    pi=acos(-1);
    scanf("%d", &teskes);
    while(teskes--){
        scanf("%ld", &l);
        for(p=0; p<5000; p++){
            x=p*p*( 2*(double)sqrt(3)-4+(double)pi/3 );
            if(x>l) break;
        }
        if(x!=p)p--;
        printf("%ld\n",p);
    }
    return 0;
}

#include <cmath>
#include <cstdio>
using namespace std;

int teskes;
double x,n;
int main(){
    scanf("%d", &teskes);
    while(teskes--){
        scanf("%lf", &n);
        x=(int)sqrt((double)n);
        printf("%.0lf\n", x);
    }
    return 0;
}

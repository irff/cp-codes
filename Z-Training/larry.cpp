#include <valarray>
#include <cstdio>
using namespace std;


valarray<double> a(13);
int main(){
    for(int i=0; i<12; i++) scanf("%lf", &a[i]);
    printf("$%.2lf\n", a.sum()/12);
    scanf("\n");
    return 0;
}

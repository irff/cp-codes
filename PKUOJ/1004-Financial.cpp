#include <cstdio>
#include <valarray>
using namespace std;

valarray<double> va(12);
int main(){
    for(int i=0; i<12; i++) scanf("%lf", &va[i]);
    printf("$%.2lf\n", (double)va.sum()/12);
}

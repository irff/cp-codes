#include <cstdio>
#include <cmath>
using namespace std;

double hang,over;
int main(){
    scanf("%lf", &hang);
    while(hang-0>0.000000000001){
        over=0.00;
        int k=0;
        for(int i=2; over<=hang; i++){
            over+=(double)1/i;
            k++;
        }
        printf("%d card(s)\n", k);
        scanf("%lf", &hang);
    }
}

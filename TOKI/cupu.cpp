#include <cstdio>
#include <cmath>

int nkotak,total,num;
double hasil;
int main() {
    scanf("%d", &nkotak);
    while(nkotak--) {
        scanf("%d", &num);
        total+=num;                 
    }
    hasil = (double) total/24;
    hasil=ceil(hasil);
    printf("%.0lf\n", hasil);
    //scanf("\n");
    return 0;    
}

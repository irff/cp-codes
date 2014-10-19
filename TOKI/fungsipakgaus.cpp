#include <cstdio>
using namespace std;

long teskes,a,b,c;
long hasil;
long pangkat(long a, long b,long c){
    long tmp;
    if(b==0) return 1;
    tmp=pangkat(a,b/2,c)%c;
    if(b%2) return (((a%c)*(tmp%c))%c*(tmp%c))%c;
    else return (tmp*tmp)%c;
}
int main(){
    scanf("%d", &teskes);
    while(teskes--){
        hasil=1;
        scanf("%ld%ld%ld", &a, &b, &c);
        for(long i=1; i<=a; i++){
            hasil=(hasil%c)*(pangkat(i,b,c)%c)%c;
        }
        printf("%ld\n", hasil);
    }
    return 0;

}

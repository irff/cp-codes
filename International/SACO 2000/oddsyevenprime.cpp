#include <cstdio>
#include <bitset>
using namespace std;

bitset<1000200> bs;
int a,b,result;
bool ada=0;
int main() {
    bs.set(); bs[0]=0,bs[1]=0;
    for(int i=2; i*i<=1000000; i++)
        for(int j=i*i; j<=1000000; j+=i) bs[j]=0;
    
    printf("Enter value for A: "); scanf("%d", &a);
    printf("Enter value for B: "); scanf("%d", &b);
    
    for(int i=a; i<=b; i++) {
        if(bs[i]) {
            int even=0,odd=0,x=i;
            while(x>0) {
                if( (x%10)%2==0) even+=(x%10);
                else odd+=(x%10);
                x/=10;
            }
            if(odd==even) {
                ada=1;
                printf("%d is an oddsy-even prime number.\n", i);
            }
        }
    }
    if(!ada) printf("No numbers found.\n");
    
    return 0;
}

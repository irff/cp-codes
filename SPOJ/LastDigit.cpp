#include <cstdio>
using namespace std;

int teskes,a,b,hasil;
int main(){
    scanf("%d", &teskes);
    while(teskes--){
        scanf("%d%d", &a,&b);
        if(b!=0) { b%=4; if(b==0) b=4; }
        hasil=1;
        for(int i=0; i<b; i++){
            hasil=(hasil%10)*a%10;
        }
        printf("%d\n", hasil%10);
    }
    return 0;
}

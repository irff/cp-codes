#include <cstdio>
#include <cmath>
using namespace std;

int x,teskes,n;
int main(){
    scanf("%d", &teskes);
    while(teskes--){
        scanf("%d", &n);
        int x=(int)sqrt(2*n);
        for(int i=x-1; i<=x+2; i++){
            if(i*(i+1)/2>=n) { printf("%d\n", i); break; }
        }
    }
    return 0;
}

#include <cstdio>
using namespace std;

int teskes, A,N,D;
int main(){
    scanf("%d", &teskes);
    while(teskes--){
        scanf("%d%d%d", &N,&A,&D);
        printf("%I64d\n", N*(2*A+(N-1)*D)/2);
    }
}

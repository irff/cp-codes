#include <cstdio>
using namespace std;

int teskes,num;
long com;
int tenpangkat(int n){
    int x=1;
    for(int i=0; i<n; i++){
        x=(x*10)%9973;
    }
    return x;
}
int main(){
    scanf("%d", &teskes);
    while(teskes--){
        scanf("%d", &num);
        com=45*tenpangkat(num-2);
        com=com+225*tenpangkat(num-3);
        com=(com-(1125*tenpangkat(num-4)%9973))%9973;
        printf("%ld\n", com);
    }
    return 0;
}

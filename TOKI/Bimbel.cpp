#include <cstdio>
using namespace std;

int a,b,d;
int c[2000];
int main(){
    scanf("%d%d", &a,&b);
    for(int i=2; i<=a+1; i++){
        c[(i+b-2)/b]++;
        //printf("%d %d\n", i, (i+b-2)/b);
    }
    d=a+1;
    for(int i=1; i<=a+1; i++){
        //printf("%d\n", c[i]);
        if(c[i]==b)  d--;
    }
    printf("%d\n", d);
    return 0;
}

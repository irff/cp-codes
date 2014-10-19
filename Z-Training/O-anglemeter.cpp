#include <cstdio>
using namespace std;

int h,m,s,i=2;
char ch;
long long n;
int main(){
    scanf("%d%c%d'%d\"",&h,&ch,&m,&s);
    n=h*3600+m*60+s;
    while(n%i==0){
        i++;
    }
    printf("%d\n", i);
    return 0;
}

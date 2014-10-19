#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int teskes;
char sa[100],sb[100],sc[100];
int main(){
    scanf("%d", &teskes);
    while(teskes--){
        char d;
        scanf("%s %c %s %c %s", &sa,&d,&sb,&d,&sc);
        //printf("%s %s %s\n", sa, sb, sc);
        if(strstr(sa,"machula")!=NULL){
            int b=atol(sb),c=atol(sc);
            printf("%d + %d = %d\n", c-b,b,c);
        } else if(strstr(sb,"machula")!=NULL){
            int a=atol(sa),c=atol(sc);
            printf("%d + %d = %d\n", a, c-a, c);
        }
        else {
            int a=atol(sa),b=atol(sb);
            printf("%d + %d = %d\n", a, b, a+b);
        }
    }
    return 0;
}

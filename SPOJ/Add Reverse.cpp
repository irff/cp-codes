#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int teskes,a,b,c;
char sa[100],sb[100],sc[100];
int main(){
    scanf("%d", &teskes);
    while(teskes--){
        scanf("%s%s",&sa,&sb);
        reverse(sa,sa+strlen(sa));
        reverse(sb,sb+strlen(sb));
        a=atoi(sa);
        b=atoi(sb);
        c=a+b;
        bool uda=0;
        while(c>0){
            if(!uda and c%10!=0) uda=1;
            if(uda) printf("%d", c%10);
            c/=10;
        }
        printf("\n");
    }
    return 0;
}

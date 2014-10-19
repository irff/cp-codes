#include <cstdio>
#include <cstring>

int a,b,c;
char ch,dummy;
int main(){
    scanf("%d%c%c%c%d", &a,&dummy,&ch,&dummy,&b);
    if(ch=='+') printf("%d\n", a+b);
    if(ch=='-') printf("%d\n", a-b);
    if(ch=='*') printf("%d\n", a*b);
    if(ch=='<') printf("%s\n", (a<b)?"benar":"salah");
    if(ch=='>') printf("%s\n", (a>b)?"benar":"salah");
    if(ch=='=') printf("%s\n", (a==b)?"benar":"salah");
    return 0;
}

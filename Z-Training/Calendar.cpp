#include <cstdio>
#include <cstring>

char s[20];
int n,x;
int main(){
    scanf("%d%s", &n,&s);
    if(strcmp(s,"saturday")==0) x=6;
    if(strcmp(s,"sunday")==0) x=7;
    if(strcmp(s,"monday")==0 and n==28) printf("0\n");
    else if(n+x>35) printf("%d\n", 42-n);
    else printf("%d\n", 35-n);
    scanf("\n");
}

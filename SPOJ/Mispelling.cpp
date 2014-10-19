#include <cstring>
#include <cstdio>

int n,teskes;
char s[10000];
int main(){
    scanf("%d", &teskes);
    
    for(int t=1; t<=teskes; t++){
        strcpy(s,"");
        scanf("%d%s", &n,&s);
        int len=strlen(s);
        printf("%d ", t);
        for(int i=0; i<len; i++) if(i+1!=n) putchar(s[i]);
        puts("");
    }

}

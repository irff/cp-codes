#include <cstdio>
#include <cstring>

char s[100];
int x,len;
int main(){
    while(1){
        scanf("%s", &s);
        if(s[0]=='.') break;
        scanf("%d", &x);
        int len=strlen(s);
        for(int i=0; i<len; i++){
            for(int j=0; j<len*x; j++){
                printf("%c", s[(j+i)%len]);
            }
            puts("");
        }
    }

}

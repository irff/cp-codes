#include <cstring>
#include <cstdio>
#include <cctype>
char s[1000];
int main(){
    gets(s);
    while(strcmp(s,"ENDOFINPUT")!=0){
        if(strcmp(s,"START")!=0 and strcmp(s,"END")!=0){
            int len=strlen(s);
            for(int i=0; i<len; i++){
                if(isupper(s[i])){
                    putchar((s[i]-'A'+21)%26+'A');
                }
                else putchar(s[i]);
            }
            puts("");
        }
        memset(s,0,sizeof s);
        gets(s);
    }
    return 0;
}

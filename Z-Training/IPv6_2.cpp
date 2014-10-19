#include <cstdio>
#include <cstring>
using namespace std;

char s[1000];
char a[40][4];
int main(){
    gets(s);
    int len=strlen(s);
    int ct=0,x=0;
    for(int i=len-1; i>=0; i--){
        if(s[i]!=':'){
             a[ct][x]=s[i]; x++; 
        }
        else ct++,x=0;
    }
    for(int i=ct; i>=0; i--){
        for(int j=3; j>=0; j--){
            printf("%c", (a[i][j]=='\0')?'0':a[i][j]);
        }
        if(i!=0) printf(":");
    }
    puts("");
    return 0;
}

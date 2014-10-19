#include <cstdio>
#include <cstring>
using namespace std;

char s[200];
int main(){
    scanf("%s", &s);
    int len=strlen(s);
    int total=len;
    for(int i=0; i<len; i++){
        if(s[i]=='c' and (s[i+1]=='-' or s[i+1]=='=') ) total--;
        if(s[i]=='d' and ((s[i+1]=='z' and s[i+2]=='=') or s[i+1]=='-')) total--;
        if( (s[i]=='s' or s[i]=='z') and s[i+1]=='=') total--;
        if( (s[i]=='l' or s[i]=='n') and s[i+1]=='j') total--;
    }
    printf("%d\n", total);
    scanf("\n");
    return 0;
}

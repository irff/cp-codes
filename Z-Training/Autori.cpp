#include <cstdio>
#include <cstring>
using namespace std;

char s[200];
int main(){
    scanf("%s", &s);
    putchar(s[0]);
    int len=strlen(s);
    for(int i=0; i<len; i++){
        if(s[i]=='-') putchar(s[i+1]);
    }
    scanf("\n");
    return 0;
}

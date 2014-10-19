#include <cstdio>
#include <cstring>
using namespace std;

int e[456980];
int n;
char s[11000],q;
int main(){
    scanf("%s", &s);
    int len=strlen(s);
    for(int i=3; i<len; i++){
        int key=(s[i]-'a')+(s[i-1]-'a')*26+(s[i-2]-'a')*676+(s[i-3]-'a')*17576;
        if(e[key]==0) e[key]=i-2;
    }
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%s", &s);
        int key=(s[3]-'a')+(s[2]-'a')*26+(s[1]-'a')*676+(s[0]-'a')*17576;
        printf("%d\n", e[key]);
    }
}

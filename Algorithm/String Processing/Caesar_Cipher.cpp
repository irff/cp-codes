#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;

char s[1000];
int main(){
    gets(s);
    for(int i=1; i<=25; i++){
        for(int j=0; j<strlen(s); j++){
            if(s[j]==' ') printf(" ");
            if(islower(s[j])) printf("%c", ((s[j]-'a')+i)%26+'a');
            if(isupper(s[j])) printf("%c", ((s[j]-'A')+i)%26+'A');
        }
        printf("\n");
    }
}

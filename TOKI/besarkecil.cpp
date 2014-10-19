#include <cstdio>
#include <cstring>
using namespace std;

int teskes;
char s[1000];
int main(){
    
    scanf("%d", &teskes);
    while(teskes--){
        scanf("%s", &s);
        for(int i=0; i<strlen(s); i++){
            if(i%2==0) printf("%c", s[i]-'a'+'A');
            else printf("%c", s[i]);
        }
        printf("\n");
    } 
    return 0;
}

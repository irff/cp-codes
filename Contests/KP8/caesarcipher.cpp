#include <cstdio>
#include <cstring>

int teskes;
char s[300];
int main () {
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%s", s);
        int len=strlen(s);
        // upper
        for(int i=0; i<len; i++ ) printf("%c", (s[i]-'a'+3)%26+'a');
        printf("\n");
        // lower
        for(int i=0; i<len; i++ ) printf("%c", (s[i]-'a'+23)%26+'a');
        printf("\n");
    }
    return 0;
}

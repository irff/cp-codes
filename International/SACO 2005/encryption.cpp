#include <cstdio>
#include <cstring>

char s[500],key[50];
int main() {
    gets(s);
    scanf("%s", key);
    int lens=strlen(s),lenkey=strlen(key);
    for(int i=0; i<lens; i++) {
        bool ada=0;
        for(int j=0; j<lenkey; j++) {
            if(s[i]==key[j]) {
                putchar(key[(j+1)%lenkey]);
                ada=1;
            }
        }
        if(!ada) putchar(s[i]);
    }
    printf("\n");
    return 0;
}

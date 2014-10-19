#include <cstdio>
#include <cstring>

char s[1002];
int main() {
    scanf("%s", s);
    int len=strlen(s);
    for(int i=0; i<len; ) {
        if(s[i]=='L' and s[i+1]=='M') printf("A"),i+=2;
        if(s[i]=='R' and s[i+1]=='S') printf("N"),i+=2;
        if(s[i]=='L' and s[i+1]=='R') {
          if(s[i+2]=='S' and s[i+3]=='M') printf("C");
          if(s[i+2]=='M' and s[i+3]=='S') printf("E");
          i+=4;
        }
        if(s[i]=='R' and s[i+1]=='L') {
            if(s[i+2]=='S' and s[i+3]=='M') printf("L");
            if(s[i+2]=='M' and s[i+3]=='S') printf("T");
            i+=4;
        }
    }
}

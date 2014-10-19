#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

char s[300], words[300][300];
int main() {
    scanf("%s", &s);
    int len = strlen(s);
    int ctr = 0, x=0;
    int state = 0;
    for(int i=0; i<len;) {
        if(s[i] == 'W' and s[i+1] == 'U' and s[i+2] == 'B') {
            if(state = 1) {
                ctr++;
                x=0;
                state = 0;
            }
            i+=3;
        } else {
            state = 1;
            words[ctr][x++]=s[i];
            i++;
        }
    }
    for(int i=0; i<ctr+1; i++) {
        if(strlen(words[i])!=0) printf("%s ", words[i]);
    }
    printf("\n");
    return 0;
}

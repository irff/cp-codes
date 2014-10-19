#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int teskes;
char s[200];
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%s", &s);
        int len = strlen(s);
        int maks = 0;
        int state = 0, bingung = 0;
        R(i,0,len) {
            if(state == 0 and s[i]=='l') state = 1;
            else if(state == 1 and s[i]=='h') state = 2;
            else if(state == 1 and s[i]=='l') state = 1;
            else if(state == 1) state = 0;
            else if(state == 2 and s[i]=='o') bingung++;
            else if(state == 2 and s[i]=='?') {
                maks = max(maks, bingung);
                state = 0;
                bingung = 0;
            } else if(state == 2 and s[i] == 'l') state = 1, bingung = 0;
            else if(state == 2) state = 0, bingung = 0;
            //alhoolho?
        }
        printf("%d\n", maks);
    }
    return 0;
}

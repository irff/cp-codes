#include <cstdio>
#include <cstring>
using namespace std;

char s[1000];
// 0 awal kata
// 1 dalam kata
int main() {
    gets(s);
    int len = strlen(s);
    int kata = 0, state = 0;
    printf("%s\n", s);
    for(int i=0; i<len; i++) {
        if(state == 0 and (s[i] >= 'a' and s[i] <= 'z')) {
            state = 1;
            kata++;
        } else if(state == 1 and (s[i] < 'a' or s[i] > 'z')) {
            state = 0;
        }
    }
    printf("%d\n", kata);
}

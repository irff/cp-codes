#include <cstdio>
#include <list>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

char s[100111];
int main() {
    while(gets(s) > 0) {
        list<char> v;
        list<char>::iterator it = v.begin();
        int len = strlen(s);
        R(i,0,len) {
            if(s[i]=='[') it = v.begin();
            else if(s[i]==']') it = v.end();
            else {
                v.insert(it,s[i]);
            }
        }
        for(it = v.begin(); it!=v.end(); it++) {
            printf("%c", *it);
        }
        printf("\n");
    }
    
    return 0;
}

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[1005];
int main(){
    gets(s);
    reverse(s,s+strlen(s));
    puts(s);
    return 0;
}

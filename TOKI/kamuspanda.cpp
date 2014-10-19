#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <list>
using namespace std;

char s[250];
list<char> a;
int teskes;
int main()
{
    scanf("%d", &teskes);
    while(teskes--){
        a.clear();
        scanf("%s", &s);
        for(int i=0; i<strlen(s); i++) a.push_back(s[i]);
        a.sort();
        a.unique();
        printf("%d\n", a.size());
    }
    return 0;
}

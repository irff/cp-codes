#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;

set<string> dict;
string str;
char s[1000];
int main() {
    char delims[] = " ,<.>/?;:'\"[{]}\\|`~!@#$%^&*()_+=-1234567890";
    while(gets(s) != 0){
        int len=strlen(s);
        for(int i=0; i<len; i++) if(isupper(s[i])) s[i]=s[i]-'A'+'a';
        char *result= NULL;
        result = strtok(s, delims);
        while(result != NULL ) {
            str.assign(result);
            dict.insert(str);
            result=strtok(NULL, delims);
        }
    }
    for(set<string>::iterator it=dict.begin(); it!=dict.end(); it++) cout << *it << endl;
    return 0;   
}

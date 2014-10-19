#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

string s[1000],str;
int id=0,ke=1;
bool immediate=1;
int main() {
    string::size_type loc;
    while( cin >> str ) {
        for(int i=0; i<id; i++) {
            loc=str.find(s[i],0);
            if(loc==0) immediate=0;
            loc=s[i].find(str,0);
            if(loc==0) immediate=0;
            if(!immediate) {
                break;
            }
        }
        
        s[id]=str;
        id++;
        if(str[0]=='9') {
            if(immediate) printf("Set %d is immediate decodable\n", ke);
            else printf("Set %d is not immediate decodable\n",ke);
            id=0;
            ke++;
            immediate=1;
        }
    }
    return 0;
}

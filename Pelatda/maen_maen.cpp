#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;
int len = 0;
int counting[1000];
int main() {
    cin >> s;
    len = s.length();
    for(int i=0; i<len; i++) counting[ s[i] ]++;
    
    for(char ch = 'Z'; ch >= 'A'; ch--) {
        string::iterator loc = find(s.begin()+1, s.end(), ch);
        while(loc!=s.end()) {
            s.erase(loc);
            loc = find(s.begin()+1, s.end(), ch);
        }
        while(counting[ch]--) {
            cout << s << endl;
        }
    }
    return 0;
}

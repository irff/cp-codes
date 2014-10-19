#include <cstdio>
#include <algorithm>
#include <string>
#include <functional>
#include <iostream>
using namespace std;

int n;
string s[12000];

bool cp(string a, string b) {
    if(a.length() == b.length()) return a < b;
    return a.length() < b.length();
}

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) cin >> s[i];
    sort(s, s+n, cp);
    for(int i=0; i<n; i++) cout << s[i] << endl;
    return 0;
}

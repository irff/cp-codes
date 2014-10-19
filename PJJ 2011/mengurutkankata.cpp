#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
string s[10100];
int main() {
    cin >> n;
    for(int i=0; i<n; i++) cin >> s[i];
    sort(s,s+n);
    for(int i=0; i<n; i++) cout << s[i] << endl;
    return 0;
}

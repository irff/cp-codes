#include <algorithm>
#include <map>
#include <cstdio>
#include <iostream>
using namespace std;

map<string,int> m;
int n;
string s;
int main() {
    scanf("%d", &n);
    while(n--) {
        cin >> s;
        if(m[s]==0) printf("OK\n");
        else {
            printf("%s%d\n", s.c_str(), m[s]);
        }
        m[s]++;
    }
    return 0;
}

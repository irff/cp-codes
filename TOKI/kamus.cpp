#include <cstdio>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

set<string> s;
string in, x;
int n;
int main() {
    scanf("%d", &n);
    while(n--) {
        cin >> in;
        if(in == "ADD") {
            cin >> x;
            s.insert(x);
        } else
        if(in == "DELETE") {
            cin >> x;
            s.erase(x);
        } else
        if(in == "CHECK") {
            cin >> x;
            if(s.find(x)==s.end()) printf("TIDAK ADA\n");
            else printf("ADA\n");
        } else
        if(in == "SIZE") {
            printf("%d\n", s.size());
        }
    }
    return 0;
}

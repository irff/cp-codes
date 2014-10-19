#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> v;
vector<string>::iterator it;
int n,pos;
string s;
int main() {
    scanf("%d", &n);
    getline(cin,s);
    for(int i=0; i<n; i++) {
        getline(cin,s);
        it=lower_bound(v.begin(),v.end(),s);
        printf("%d\n", it-v.begin()+1);
        v.insert(it,s);
    }
    return 0;
}

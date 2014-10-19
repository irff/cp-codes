#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int teskes,n;
string s[50111];
int main(){
    scanf("%d", &teskes);
    while(teskes--){
        scanf("%d", &n);
        for(int i=0; i<n; i++) cin >> s[i];
        sort(s,s+n);
        for(int i=0; i<n; i++) cout << s[i] << endl;
    }
    return 0;
}

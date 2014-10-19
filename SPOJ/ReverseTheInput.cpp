#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

typedef vector<string> VS;

VS vp;
string s;
int n;
int main(){
    scanf("%d", &n);
    while(cin >> s > 0){
        reverse(s.begin(),s.end());
        vp.push_back(s);
    }
    while(!vp.empty()){
        for(int i=0; i<n; i++){
            cout << vp.back();
            cout << " ";
        }
        vp.pop_back();
    }
    return 0;
}

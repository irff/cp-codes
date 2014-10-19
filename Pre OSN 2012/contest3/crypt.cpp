#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <string>
#include <sstream>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

map<string, bool> dict;
int n;
string s; 

char m[30][30][30];

int main() {
    scanf("%d", &n);
    R(i,0,n) {
        cin >> s;
        dict[s]=1;
    }
    R(i,0,26) {
       R(j,0,26) {
           R(k,0,26) {
               m[i][j]=k+'a';
           }
       }
    }
    while(getline(cin,s) > 0) {
        stringstream ss;
        ss << s;
        string x;
        while(ss >> x !=0) {
            
        }
    }
    return 0;
}

/*
        string x;
        const char * zz = s.c_str();
        while(sscanf(zz, " ",x.c_str())>0) {
            cout << x;
        }
*/

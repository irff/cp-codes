#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

typedef map<string,string> MSS;

int V, E;
MSS p;
int main() {
    scanf("%d%d", &V, &E);
    R(i,0,E) {
        string a, b;
        cin >> a >> b;
        p[b] = a;
    }
    string a, b;
    cin >> a >> b;
    
    string x = a;
    bool nemu = 1;
    vector<string> solusi_1;
    while(x!=b) {
        solusi_1.push_back(x);
        if(p[x]=="") {
            nemu = 0;
            break;
        }
        x = p[x];
    }
    solusi_1.push_back(x);
    if(nemu) {
        int len = solusi_1.size();
        RV(i,len-1,0) cout << solusi_1[i] << endl;
    } else {
        string x = b;
        vector<string> solusi_2;
        bool nemu = 1;
        while(x!=a) {
            solusi_2.push_back(x);
            if(p[x]=="") {
                nemu = 0;
                break;
            }
            x = p[x];
        }
        solusi_2.push_back(x);
        if(nemu) {
            int len = solusi_2.size();
            RV(i,len-1,0) cout << solusi_2[i] << endl;
        } else cout << "TIDAK MUNGKIN\n" ;
    }
    return 0;
}

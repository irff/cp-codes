#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

string in;

struct BinaryCode {
    vector<string> decode(string message) {
        int len = message.length();
        string sa(len,0),si(len,0);
        string p = message;
        vector<string> sol;
        R(i,0,len) p[i]-='0';
        sa[0] = 0;
        R(i,0,len-1) {
            if(i==0) {
                sa[1] = p[0]-sa[0];
            } else if(i==len-2) {
                sa[i+1] = p[i+1]-sa[i];
            } else {
                sa[i+1] = p[i]-sa[i]-sa[i-1];
            }
        }
        bool bisa_a = 1;
        R(i,0,len) {
            if(sa[i]<0 or sa[i] > 1) {
                bisa_a = 0;
                break;
            }
        }
        if(bisa_a) {
            R(i,0,len) sa[i]+='0';
            sol.push_back(sa);
        } else sol.push_back("NONE");
        
        si[0] = 1;
        R(i,0,len-1) {
            if(i==0) {
                si[1] = p[0]-si[0];
            } else if(i==len-2) {
                si[i+1] = p[i+1]-si[i];
            } else {
                si[i+1] = p[i]-si[i]-si[i-1];
            }
        }
        bool bisa_b = 1;
        R(i,0,len) {
            if(si[i] < 0 or si[i] > 1) {
                bisa_b = 0;
                break;
            }
        }
        if(bisa_b) {
            R(i,0,len) si[i]+='0';
            sol.push_back(si);
        } else sol.push_back("NONE");
        return sol;
    }
};

BinaryCode x;

int main() {
    cin >> in;
    vector<string> t = x.decode(in);
    cout << t[0] << endl << t[1] << endl;
    return 0;
}

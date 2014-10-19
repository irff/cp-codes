#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define kiri 0
#define kanan 1

int len, Q;
string ori, s;
int a, b, m[12];

bool kosong(string s) {
    int len = s.length(), ctr = 0;
    
    R(i,0,len) {
        if(s[i] == '-') ctr++;
    }
    return ctr == len;
}

int main() {
    scanf("%d%d", &len, &Q);
    cin >> ori;
    R(i,0,Q) {
        R(i,0,10) m[i] = 0;
        int c = 0, dir = kanan, pos = 0;
        char tadi = 0;
        scanf("%d%d", &a, &b);
        
        s = ori.substr(a-1,b-a+1);
        c = 0;
        int len = s.length();
        while(!kosong(s) and c>=0 and c<len) {
            if(s[c] == '-') {
                if(dir==kiri) c--;
                else c++;
            } else if(s[c]>='0' and s[c]<='9') {
                tadi = s[c];
                
                m[ s[c]-'0' ]++;
                
                if(s[c]>'0') s[c]--;
                else {
                    s[c] = '-';
                }
                if(dir==kiri) c--;
                else c++;
                
            } else if(s[c]=='>') {
                char now = s[c];
                if(tadi == '>') {
                    s[pos] = '-';
                } else if(tadi=='<') {
                    s[pos] = '-';
                }
                tadi = now;
                pos = c;
                c++;
                dir = kanan;
            } else if(s[c]=='<') {
                char now = s[c];
                if(tadi == '>') {
                    s[pos] = '-';
                } else if(tadi == '<') {
                    s[pos] = '-';
                }
                tadi = now;
                pos = c;
                c--;
                dir = kiri;
            }
        }
        R(i,0,10) {
            printf("%d ", m[i]);
        }
        printf("\n");
    }
    return 0;
}

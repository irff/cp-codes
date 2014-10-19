#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

char tc[100];
string key, d[200], awal, akhir;
int n, len = 0;
int main() {
    gets(tc);
    cin >> key;

    len = key.length();
    int separator = 0;
    R(i,0,len) {
        if(key[i] == '*') {
            separator = i;
            break;
        }
    }
    
    R(i,0,separator) awal.push_back(key[i]);
    R(i,separator+1,len) akhir.push_back(key[i]);
    int lena = awal.length(), leni = akhir.length();

    scanf("%d", &n);
    
    R(i,0,n) {
        cin >> d[i];
        bool jadi = 1;
        int dilen = d[i].length();
        if(dilen < lena+leni) jadi = 0;
        R(j,0,lena) if(awal[j] != d[i][j]) { jadi = 0; break; }
        R(j,0,leni) if(akhir[leni-j-1] != d[i][dilen-j-1]) { jadi = 0; break; }
        if(jadi) cout << d[i] << endl;
    }

    return 0;
}

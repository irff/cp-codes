#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n, nquery;
string s[12000], num[12000], str;

void binary(int awal, int akhir) {
    int mid = (awal+akhir)/2;
    if(s[mid] < str) {
        awal = mid+1;
    }
    if(s[mid]==str) {
        cout << num[mid] << endl;
        return ;
    }
    if(s[mid] > str) {
        akhir = mid-1;
    }
    binary(awal, akhir);
}

int main() {
    cin >> n >> nquery;
    R(i,0,n) {
        cin >> s[i] >> num[i];
    }
    R(i,0,nquery) {
        cin >> str;
        binary(0,n);
    }
    return 0;
}

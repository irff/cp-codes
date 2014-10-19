#include <cstring>
#include <map>
#include <string>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

string asli, s[30];
int n, x[30];

int main() {
    cin >> asli;
    cin >> n;
    R(i,0,n) {
        cin >> s[i];
    }
    sort(asli.begin(), asli.end());
    int ctr = 0;
    R(i,0,n) {
        if(asli==s[i]) x[i] = ctr;
    }
    while(next_permutation(asli.begin(), asli.end())) {
        ctr++;
        R(i,0,n) {
            if(asli==s[i]) x[i] = ctr;
        }
    }
    R(i,0,n-1) {
        printf("%d\n", abs(x[i]-x[i+1]));
    }
    return 0;
}

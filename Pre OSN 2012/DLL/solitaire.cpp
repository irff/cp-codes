#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

string deck[60];
list<string> x;
int n;
bool jadi = 0;

void rek(list<string> x, int n) {
    if(n == 1) {
         jadi = 0; return ;
    }
    for(int i=n-1; i>=0; i--) {
        if(i>0) {
            list<string> s = x;
            list<string>::iterator it = s.begin();
            advance(it, i);
            x.erase(it)
        }
        
        
    }
    
}

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        cin >> deck[i];
        x.insert(x.end(), deck[i]);
    }
    rek(x,n);
    return 0;
}

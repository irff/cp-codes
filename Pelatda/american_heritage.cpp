#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

string pre, in, post;
int now = 0;

void rek(string pre) {
    int len = pre.length();
    if( len == 1 ) {
        cout << pre;
        now++;
    } else {
      int lok = 0;
      for(int i=0; i<len; i++) if(pre[i]==in[now]) lok = i;
    
      now++;
      if(pre.length() > 1) {
        string ki = "";
        for(int i=0; i<lok; i++) ki.push_back(pre[i]);
        string ka = "";
        for(int i=lok+1; i<len; i++) ka.push_back(pre[i]);
        if(ki.length()) rek(ki);
        if(ka.length()) rek(ka);
        cout << pre[lok];
      }
    }
    
}

int main() {
    cin >> pre >> in;
    rek(pre);
    printf("\n");
    return 0;
}

#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

map<string,int> m;

string s;
int now = 1;
int main() {
    R(i,0,26) {
        s = ""; s.push_back(i+'a');
        m[s] = now++;
    }
    R(i,0,26) {
      R(j,i+1,26) {
        s = ""; s.push_back(i+'a'); s.push_back(j+'a');
        m[s] = now++;
      }
    }
    R(i,0,26) {
      R(j,i+1,26) {
          R(k,j+1,26) {
            s = ""; s.push_back(i+'a'); s.push_back(j+'a'); s.push_back(k+'a');
            m[s] = now++;
          }
      }
    }
    R(i,0,26) {
      R(j,i+1,26) {
          R(k,j+1,26) {
            R(l,k+1,26) {
              s = ""; s.push_back(i+'a'); s.push_back(j+'a'); s.push_back(k+'a');
              s.push_back(l+'a');
              m[s] = now++;
            }
          }
      }
    }
    
    R(i,0,26) {
      R(j,i+1,26) {
          R(k,j+1,26) {
            R(l,k+1,26) {
              R(n,l+1,26) {
                s = ""; s.push_back(i+'a'); s.push_back(j+'a'); s.push_back(k+'a');
                s.push_back(l+'a'); s.push_back(n+'a');
                m[s] = now++;
              }
            }
          }
      }
    }
    while( cin >> s ) {
        printf("%d\n", m[s]);
    }
    return 0;
}

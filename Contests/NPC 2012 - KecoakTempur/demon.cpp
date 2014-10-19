#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int teskes, ndemon;
string s,d;
int main() {
    scanf("%d\n", &teskes);
    
    while(teskes--) {
        getline(cin,s);
        //printf("%s\n", s);
        int lena = s.length();
        scanf("%d\n", &ndemon);
        R(i,0,ndemon) {
            getline(cin, d);
            int leni = d.length(), pos = 0;
            string::size_type = s.find(d,0);
            if(nemu) printf("%d\n", pos);
            else printf("ERROR 404 DEMON NOT FOUND\n");
        }
    }
    return 0;
}

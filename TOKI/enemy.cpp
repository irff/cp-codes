#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int joko, enemy;
int hp, tipe;

int to_int(string s_in) {
    int num;
    istringstream(s_in) >> num;
    return num;
}

string to_string(int s) {
   char x[1000];
   sprintf(x,"%d",s);
   string ret=x;
   return ret;
}

int main() {
    scanf("%d%d", &joko, &enemy);
    while(enemy--) {
        int mins = 2000111222;
        scanf("%d%d\n", &hp, &tipe);
        R(i,0,tipe) {
            string s, num = "";
            getline(cin, s);
            int len = s.length();
            
            R(j,0,len) {
                if(s[j]>='0' and s[j] <='9') num.push_back(s[j]);
            }
            int x = to_int(num);
            //printf("%d\n", x);
            mins = min(mins, x);
        }
        int n_serang = hp/joko;
        //printf("nserang = %d\n", n_serang);
        if(n_serang*joko!=hp) n_serang++;
        int damage   = n_serang*mins;
        printf("%d\n", damage);
    }
    return 0;
}

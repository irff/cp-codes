#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

string s;
int memo[200][200];
int rek(int a, int b) {
    int hasil=100;
    
    if(memo[a][b]!=-1) return memo[a][b];
    else{
        if(a==b) return memo[a][b]=1;
        else {
            bool sama=1;
            for(int i=a; i<=(a+b)/2; i++) {
                if(s[i]!=s[a+b-i]) sama=0;
            }
            if(sama) return memo[a][b]=1;
        
            // DnC spirits!!!
            for(int i=a; i<b; i++) {
                hasil=min(hasil, rek(a, i)+rek(i+1, b));
            }
            return memo[a][b]=hasil;
        }
    }
}

int main() {
    memset(memo, -1, sizeof memo);
    cin >> s;
    int hasil=rek(0,s.length()-1);
    printf("%d\n", hasil);
    return 0;
}

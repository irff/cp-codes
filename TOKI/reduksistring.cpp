#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

string str;
int mins,teskes;
int main(){
    scanf("%d", &teskes);
    while(teskes--){
        cin >> str;
        int i=0;
        while(1){
            if(str[i]==str[i+2] and i+2<str.length()) str.erase(i,2),i=0;
            else { i++; }
            if( i >= str.length() ) break;
        }
        mins=str.length();
        printf("%d\n", mins);
    }
    return 0;
}

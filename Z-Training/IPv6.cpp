#include <cstring>
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

string s;
char x[1000];
int main(){
    cin >> s;
    int len=s.size();
    int c=0;
    for(int i=0; i<len; i++){
        if(i==0 and s[i]==':') x[c]='0',c++,x[c]=':',c++;
        else if(s[i]==':' and s[i+1]==':') x[c]=':',c++,x[c]='0',c++;
        else if(s[i]==':' and s[i-1]==':') x[c]=':',c++;
        else x[c]=s[i],c++;
    }
    int lenx=strlen(x);
    //cout << x;
    //puts("");
    for(int i=0; i<lenx;){
        if(i==0) {
            int c=i,r=0;
            while(x[c]!=':') c++,r++;
            for(int j=0; j<4-r; j++) putchar('0');
            for(int j=0; j<r; j++) putchar(x[j]);
            i+=r;
        }else{
            if(x[i]==':') i++;
            putchar(':');
            int c=i,r=0;
            while(x[c]!=':' and x[c]!='\0') c++,r++;
            for(int j=0; j<4-r; j++) putchar('0');
            for(int j=0; j<r; j++) putchar(x[i+j]);
            i+=r;
        }
    }
    return 0;
}

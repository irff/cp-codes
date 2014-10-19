#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int sec;

struct Time {
    string whatTime(int seconds) {
        string sh = "";
        int hour = seconds/3600;
        if(hour==0) sh = "0";
        while(hour > 0) sh.push_back(hour%10+'0'),hour/=10;
        reverse(sh.begin(), sh.end());
        string sm = "";
        int minute = (seconds%3600)/60;
        if(minute == 0) sm = "0";
        while(minute > 0) sm.push_back(minute%10+'0'), minute/=10;
        reverse(sm.begin(), sm.end());
        string ss = "";
        int sec = seconds%60;
        if(sec == 0) ss = "0";
        while(sec > 0) ss.push_back(sec%10+'0'), sec/=10;
        reverse(ss.begin(), ss.end());
        return sh+":"+sm+":"+ss; 
    }
};

Time x;

int main() {
    scanf("%d", &sec);
    cout << x.whatTime(sec) << endl;
    return 0;
}

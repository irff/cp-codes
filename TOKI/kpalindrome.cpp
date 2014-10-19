#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char s[2000];
int maks,chance,teskes;
int main(){
    scanf("%d", &teskes);
    while(teskes--){
        // init
        maks=-1;
        scanf("%s %d", &s, &chance);
        int p=strlen(s);
        for(int i=0; i<p; i++){ // O(n)
            // init
            int a=-1,b=0,ca=chance,cb=chance;
            bool samaa=1,samab=1;
            int x=0;
            while( i-x >= 0 and i+x < p ){
                // odd palin
                if(s[i-x]==s[i+x] or ca-->0) a+=2;    // always +2 & counter-case
                else samaa=0; // stops
                // even palin
                if(s[i-x]==s[i+x+1] or ( cb-->0 and i+x+1 < p )) b+=2;      // always +2
                else samab=0; // stops
                // enough?
                if( !samaa and !samab ) break;
				x++;
            }
            // the 'greatest'
            maks=max(maks,max(a,b));
            if(maks==strlen(s)) break;
        }
        printf("%d\n", maks);
    }
    return 0;
}

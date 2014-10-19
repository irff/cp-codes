#include <cstdio>
#include <cstring>
using namespace std;

char s[100000];
int n;
int main(){
    scanf("%s", &s);
    int len=strlen(s);
    int state=5;
    for(int i=0; i<len; i++){
        if(state==1){
            if(s[i]=='2' or s[i]=='4') n+=1;
            if(s[i]=='3' or s[i]=='5' or s[i]=='7') n+=2;
            if(s[i]=='8' or s[i]=='6') n+=3;
            if(s[i]=='0' or s[i]=='9') n+=4;
            state=s[i]-'0';
        }else if(state==2){
            if(s[i]=='1' or s[i]=='3' or s[i]=='5') n+=1;
            if(s[i]=='4' or s[i]=='6' or s[i]=='8') n+=2;
            if(s[i]=='0' or s[i]=='9' or s[i]=='7') n+=3;
            state=s[i]-'0';
        } else if(state==3){
            if(s[i]=='2' or s[i]=='6') n+=1;
            if(s[i]=='1' or s[i]=='5' or s[i]=='9') n+=2;
            if(s[i]=='4' or s[i]=='8') n+=3;
            if(s[i]=='7' or s[i]=='0') n+=4;
            state=s[i]-'0';
        } else if(state==4){
            if(s[i]=='1' or s[i]=='5' or s[i]=='7') n+=1;
            if(s[i]=='2' or s[i]=='6' or s[i]=='8') n+=2;
            if(s[i]=='3' or s[i]=='9' or s[i]=='0') n+=3;
            state=s[i]-'0';
        } else if(state==5){
            if(s[i]=='2' or s[i]=='4' or s[i]=='6' or s[i]=='8') n+=1;
            if(s[i]=='1' or s[i]=='3' or s[i]=='7' or s[i]=='9' or s[i]=='0') n+=2;
            state=s[i]-'0';
        } else if(state==6){
            if(s[i]=='3' or s[i]=='5' or s[i]=='9') n+=1;
            if(s[i]=='2' or s[i]=='4' or s[i]=='8') n+=2;
            if(s[i]=='1' or s[i]=='7' or s[i]=='0') n+=3;
            state=s[i]-'0';
        } else if(state==7){
            if(s[i]=='4' or s[i]=='8')n+=1;
            if(s[i]=='1' or s[i]=='5' or s[i]=='9' or s[i]=='0') n+=2;
            if(s[i]=='2' or s[i]=='6') n+=3;
            if(s[i]=='3') n+=4;
            state=s[i]-'0';
        } else if(state==8){
            if(s[i]=='7' or s[i]=='0' or s[i]=='5' or s[i]=='9')n+=1;
            if(s[i]=='4' or s[i]=='2' or s[i]=='6') n+=2;
            if(s[i]=='1' or s[i]=='3') n+=3;
            state=s[i]-'0';
        } else if(state==9){
            if(s[i]=='6' or s[i]=='8')n+=1;
            if(s[i]=='0' or s[i]=='3' or s[i]=='5' or s[i]=='7') n+=2;
            if(s[i]=='2' or s[i]=='4') n+=3;
            if(s[i]=='1') n+=4;
            state=s[i]-'0';
        } else if(state==0){
           if(s[i]=='8')
           if(s[i]=='7' or s[i]=='5' or s[i]=='9')n+=1;
           if(s[i]=='4' or s[i]=='2' or s[i]=='6') n+=2;
           if(s[i]=='1' or s[i]=='3') n+=3;
            state=s[i]-'0';
        }
    }
    printf("%d\n", n);
    return 0;
}

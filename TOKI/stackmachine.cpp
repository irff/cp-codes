#include <cstdio>
#include <algorithm>
#include <deque>
#include <cstring>
using namespace std;

deque<char> q;
deque<char>::iterator it;
char a[1000];
int teskes;
int main(){
    scanf("%d", &teskes);
    gets(a);
    while(teskes--){
        q.clear();
	gets(a);
        for(int i=0; i<strlen(a); i++){
            if(a[i]=='+') q.push_back(a[i+1]);
            if(a[i]=='^') reverse(q.begin(),q.end());
        }
        for(it=q.begin(); it!=q.end(); it++) printf("%c", *it);
        printf("\n");
    }
    return 0;
}

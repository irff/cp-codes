#include <stack>
#include <cstdio>
using namespace std;
int n;
int main(){
    scanf("%d", &n);
    while(n!=0){
        stack<int> a,b,c,x;
        c.push(0);
        bool jadi=0;
        int num;
        for(int i=0; i<n; i++) scanf("%d", &num),x.push(num);
        while(!x.empty()) a.push(x.top()),x.pop();
        while(!a.empty() or !b.empty()){
            //printf("%d\n",c.top());
            if(!a.empty() and c.top()+1==a.top()) c.push(a.top()),a.pop();
            if(!b.empty() and c.top()+1==b.top()) c.push(b.top()),b.pop();
            if(!a.empty()) b.push(a.top()),a.pop();
            if(a.empty() and c.size()==n+1 and b.empty()) { jadi=1; break; }
            if(a.empty() and c.size()!=n+1 and !b.empty() and b.top()!=c.top()+1) { jadi=0; break; }
        }
        //printf("C :");
        //while(!c.empty()) printf("%d ", c.top()),c.pop();
        //puts("");
        //printf("B :");
        //while(!b.empty()) printf("%d ", b.top()),b.pop();
        //puts("");
        //printf("A :");
        //while(!a.empty()) printf("%d ", a.top()),a.pop();
        printf("%s\n", (jadi)?"yes":"no");
        scanf("%d", &n);
    }
    return 0;
}

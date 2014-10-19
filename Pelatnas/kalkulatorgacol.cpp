#include <cstdio>
#include <stack>
#include <algorithm>
#include <cstring>
#include <cctype>
using namespace std;

stack<char> op,num;
char s[100];
int priority(char x) {
    if(x=='+' or x=='-') return 0;
    if(x=='*' or x=='/') return 1;
}
int main() {
    scanf("%s", s);
    int len=strlen(s);
    for(int i=0; i<len; i++) {
        if(isdigit(s[i])) {
            num.push(s[i]);
            putchar(s[i]);
        } else {
            if(s[i]=='(') op.push(s[i]);
            else if(s[i]==')') {
                while(!op.empty() and op.top() != '(') {
                    putchar(op.top());
                    op.pop();
                }
                op.pop();
            } else if(!op.empty()) {
                char t=op.top();
                if(t!='(' and priority(s[i]) > priority(t)) {
                    op.push(s[i]);
                } else if( t!='(' and priority(s[i]) == priority(t) ) {
                        putchar(op.top());
                        op.pop();
                        op.push(s[i]);
                } else {
                    while(!op.empty() and op.top()!='(' and priority(s[i]) <= priority(op.top()) ) {
                        putchar(op.top());
                        op.pop();
                    }
                    op.push(s[i]);
                }
            } else {
                op.push(s[i]);
            }
        }
    }
    while(!op.empty()) {
        putchar(op.top());
        op.pop();
    }
    printf("\n");
    return 0;
}

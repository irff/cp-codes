queue<PII> q;

// try to walk
void trywalk(int i,int j){
    if(a>=0 and a<bar and b>=0 and b<kol and m[i][j]!='#'){
        m[i][j]='#';
        q.push(PII(a,b));
    }
}

// main process
R(i,0,bar) R(j,0,kol) 
    if(m[i][j]!='#') { 
      q.push(PII(i,j));
      m[i][j]='#';
      while(!q.empty()){
        com++;
        PII t=q.front(); q.pop();
        trywalk(t.x-1,t.y);
        trywalk(t.x,t.y+1);
        trywalk(t.x+1,t.y);
        trywalk(t.x,t.y-1);
      }
    }
    
    printf("%d\n", MAX);

vector<int> pset(10111);
priority_queue<PIII> pq;

void initset(int _size){ R(i,0,_size+1) pset[i]=i;}
int findset(int i){ return (pset[i]==i)?i:(pset[i]=findset(pset[i])); }
void join(int i, int j){ pset[findset(i)]=pset[findset(j)]; }
bool sameset(int i, int j){ return findset(i)==findset(j); }

int main(){
    int cost=0; initset(V);
    while(!pq.empty()){
        PIII f=pq.top(); pq.pop();
        if(!sameset(f.second.first,f.second.second)){ // if no cycle
            cost+=(-f.first); // negated edge weight
            join(f.second.first,f.second.second);
        }
    }
    printf("%d\n", cost);
}

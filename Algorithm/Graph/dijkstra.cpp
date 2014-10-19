void dijk(int s) {
     vector<int> dist(V+2, INF);
     priority_queue<PII, VII, greater<PII> > pq;
     dist[s]=0;
     pq.push(PII(0,s));
     
     while(!pq.empty()){
        PII TOP=pq.top(); pq.pop();
        int d=TOP.first, u=TOP.second;
        
        if(d == dist[u]){
            VR(adj[u], it){
                int v = it -> first, w = it -> second;
                if(dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                    pq.push(PII(dist[v], v));
                } //endif
            } //endfor
        } //endif
    } //endwhile
    
}

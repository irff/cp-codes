
//reverse coin change
// KNAPSACK 1 <=
R(i,1,N+1) 
    RV(j,Max,w[i])
        result[j] = max(result[j], result[j-w[i]] + c[i]);

// KNAPSACK 1 ==
R(i,1,N+1) RV(j,Max,w[i]) if(result[j-w[i]]) result[j] = max(result[j], result[j-w[i]] + c[i]);

// KNAPSACK >1 <=
R(i,1,N+1) R(j,w[i],Max+1) result[j] = max(result[j], result[j-w[i]] + c[i]);
// KNAPSACK >1 ==
R(i,1,N+1) R(j,w[i],Max+1) if(result[j-w[i]]) result[j] = max(result[j], result[j-w[i]] + c[i]);

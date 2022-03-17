class Solution {
public:
  //  int c=0;
    class UnionFind {
    vector<int> parent;
    vector<int> size;
public:
        int c=0;
    UnionFind(int n) {
        parent.resize(n);
        size.resize(n, 1);
       // int c=0;
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    int Find(int u) {
        if (u == parent[u]) return u;
        return parent[u] = Find(parent[u]); // Path compression -> logN
    }
   void Union(int u, int v) {
        int pu = Find(u), pv = Find(v);
       if(pu==pv)
       {
           return;
       }
       c++;
        if (size[pu] < size[pv]) { // merge u into v
            size[pv] += size[pu];
            parent[pu] = pv;
        } else {
            size[pu] += size[pv];
            parent[pv] = pu;
        }
        
    }
};
    
    int removeStones(vector<vector<int>>& stones) {
        
        int i,n=stones.size(),c=0,j;
        
        UnionFind u(n+5);
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                  if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                  { u.Union(i,j);}
            
            }
        }
        
        /*
        for(i=0;i<n;i++)
        {
            if(parent[i]==i)
            {
                c++;
            }
        }
        */
        return u.c;
        
    }
};
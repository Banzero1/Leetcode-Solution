class Solution {
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<long long> s1, s2, s3;
        vector<vector<vector<int> > > es(n+1);
        vector<vector<vector<int> > > es2(n+1);
        for(auto x: edges){
            es[x[0]].push_back(vector<int>{x[1], x[2]});
            swap(x[0], x[1]);
            es2[x[0]].push_back(vector<int>{x[1], x[2]});
        }
        auto dijkstra = [&](int s, vector<long long>& dis, vector<vector<vector<int> > >& e){
            dis.assign(n+1, 1e11);
            dis[s] = 0;
            priority_queue<pair<long long, int> > PQ;
            PQ.push({0, s});
            while(!PQ.empty()){
                auto x = PQ.top(); PQ.pop();
                if(-x.first != dis[x.second])
                    continue;
                x.first = -x.first;
                for(auto v: e[x.second]){
                    if(dis[v[0]] > x.first + v[1]){
                        dis[v[0]] = x.first + v[1];
                        PQ.push({-dis[v[0]], v[0]});
                    }
                }
            }
        };
        dijkstra(src1, s1, es);
        dijkstra(src2, s2, es);
        dijkstra(dest, s3, es2);
        long long ans = 1e11;
        for(int i=0; i<=n; i++)
            ans = min(ans, s1[i] + s2[i] + s3[i]);
        return ans >= 1e11 ? -1 : ans;
    }
};
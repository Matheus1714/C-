#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class DisjoinSets{
    public:
        int *parent, *rnk;
        int n;
        DisjoinSets(int n){
            this->n = n;
            this->parent = new int[n+1];
            this->rnk = new int[n+1];
            for(int i = 0; i <= n; i++){
                this->rnk[i] = 0;
                this->parent[i] = i;
            }
        }
        int find(int u){
            if(u != this->parent[u]) this->parent[u] = this->find(this->parent[u]);
            return this->parent[u];
        }
        void merge(int x, int y){
            x = this->find(x), y = this->find(y);
            if(this->rnk[x] > this->rnk[y]) this->parent[y] = x;
            else this->parent[x] = y;
            if(this->rnk[x] == this->rnk[y]) this->rnk[y]++;
        }
};

class Graph{
    public:
        int V; // Vertex
        int E; // Edges
        vector<pair<int, pair<int, int>>> edges; // Adj Matrix
        Graph(int v, int e){
            this->V = v;
            this->E = e;
        }
        void addEdge(int vi, int vf, int w){
            this->edges.push_back(make_pair(w, make_pair(vi, vf)));
        }
        int kruskaMST(){
            int mst_wt = 0;
            sort(this->edges.begin(), this->edges.end());
            DisjoinSets ds(this->V);
            vector<pair<int, pair<int, int>>>::iterator it;
            for(it=this->edges.begin(); it != this->edges.end(); it++){
                int u = it->second.first;
                int v = it->second.second;

                int set_u = ds.find(u);
                int set_v = ds.find(v);

                if(set_u != set_v){
                    mst_wt += it->first;
                    ds.merge(set_u, set_v);
                }
            }
            return mst_wt;
        }
};

int main(){
    int m, n, x, y, z;
    int wst;
    while(true){
        cin>>m>>n;
        if(x == 0 && y == 0) break;
        Graph g(m, n);
        int total_weight = 0;
        for(int i = 0; i < n; i++){
            cin >> x >> y >> z;
            g.addEdge(x, y, z);
            total_weight += z;
        }
        cin>>m>>n; // read row with 0 0
        int mst_wt = g.kruskaMST();
        cout << total_weight - mst_wt << endl;
    }
    return 0;
}
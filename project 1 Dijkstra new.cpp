#include <bits/stdc++.h>
#define up(i,a,b) for (int i = (int)a; i <= (int)b; i++)
#define pii pair<int, int>
using namespace std;

const int MOD = 1e9 + 7;

vector<vector<pii> > a;
vector<int> before;
vector<int> height;

priority_queue<pair<int, int> > PQ; //Max priority queue for height
void Dijkstra_new(int s, int t){
    height[s] = MOD;
    PQ.push(make_pair(height[s], s));

    while (!PQ.empty()){
        pii p = PQ.top();
        int curr_height = p.first;
        int u = p.second;
        PQ.pop();

        if (curr_height < height[u]) continue;
        if (u == t) continue;
        
        for (pii g : a[u]){
            int v = g.first;
            int w = g.second;
            int new_h = min(curr_height, w);
            if (new_h > height[v]){
                height[v] = new_h;
                before[v] = u;
                PQ.push(make_pair(height[v], v));
            }
        }
    }
}

void find_trace(int s, int t){
    vector<int> path;
    path.push_back(t);
    while (t != s){
        t = before[t];
        path.push_back(t);
    }
    reverse(path.begin(), path.end());
    for (int x : path) cout << x << " ";
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #define Task "A"
    if (fopen(Task".inp", "r")){
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }

    int n,m,s,t;
    cin >> n >> m >> s >> t;

    a.resize(n+1, vector<pii>());
    before.resize(n+1, 0);
    height.resize(n+1, 0);

    up(i,1,m){
        int u,v,w;
        cin >> u >> v >> w;
        a[u].push_back(make_pair(v, w));
        a[v].push_back(make_pair(u, w));
    }

    Dijkstra_new(s, t);
    cout << height[t];

    cout << "\n";
    find_trace(s, t);
}

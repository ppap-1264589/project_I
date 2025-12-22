#include <bits/stdc++.h>
#define up(i,a,b) for (int i = (int)a; i <= (int)b; i++)
using namespace std;

vector<vector<pair<int, int> > > a;
vector<bool> marked;
vector<int> parrent;

void find_trace(int s, int t){
    vector<int> path;
    path.push_back(t);
    while (t != s){
        t = parrent[t];
        path.push_back(t);
    }
    reverse(path.begin(), path.end());
    for (int x : path) cout << x << " ";
    cout << "\n";
}

bool DFS(int u, int t, int curr_height){
    if (u == t) return true;
    for (pair<int, int> p : a[u]){
        int v = p.first;
        int w = p.second;
        if (w < curr_height) continue;
        if (marked[v]) continue;
        marked[v] = true;
        parrent[v] = u;
        if (DFS(v, t, curr_height)) return true;
    }
    return false;
}

bool can_pass(int s, int t, int curr_height){
    fill(marked.begin(), marked.end(), false);
    marked[s] = true;
    if (DFS(s, t, curr_height)) return true;
    return false;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #define Task "A"
    if (fopen(Task".inp", "r")){
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }

    int maxx = 0;
    int n,m,s,t;
    cin >> n >> m >> s >> t;

    a.resize(n+1, vector<pair<int, int> >());
    marked.resize(n+1, false);
    parrent.resize(n+1);

    up(i,1,m){
        int u,v,w;
        cin >> u >> v >> w;
        a[u].push_back(make_pair(v, w));
        a[v].push_back(make_pair(u, w));
        maxx = max(maxx, w);
    }


    int L = 0;
    int R = maxx+1;
    while (R - L > 1){
        int mid = (L + R) >> 1;
        if (can_pass(s, t, mid)) L = mid;
        else R = mid;
    }

    cout << L << "\n";
    find_trace(s, t);
}

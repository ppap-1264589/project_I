#include <bits/stdc++.h>
#define up(i,a,b) for (int i = (int)a; i <= (int)b; i++)
#define pii pair<int, int>
using namespace std;

const int MOD = 1e9 + 7;

vector<vector<pii> > a;
vector<bool> marked;
vector<int> temp_path;
vector<int> true_path;


int best = 0;

void update_solution(int found_answer){
    if (best < found_answer){
        best = found_answer;
        true_path = temp_path;
    }
}

void Try(int u, int curr_min, int destination){
    if (u == destination){
        update_solution(curr_min);
        return;
    }

    for (pii p : a[u]){
        int v = p.first;
        int w = p.second;

        if (marked[v]) continue;

        int new_curr_min = min(curr_min, w);
        if (new_curr_min <= best) continue;

        marked[v] = true;
        temp_path.push_back(v);
        Try(v, new_curr_min, destination);
        temp_path.pop_back();
        marked[v] = false;
    }
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
    marked.resize(n+1, false);

    up(i,1,m){
        int u,v,w;
        cin >> u >> v >> w;
        a[u].push_back(make_pair(v, w));
        a[v].push_back(make_pair(u, w));
    }


    marked[s] = true;
    temp_path.push_back(s);
    Try(s, MOD, t);


    cout << best;

    cout << "\n";
    for (int x : true_path) cout << x << " ";
}

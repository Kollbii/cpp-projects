// https://csacademy.com/contest/archive/task/check-dfs/statement/
/*
4 6
1 4 2 3
1 2
1 3
1 4
3 2
4 2
3 4
*/

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <queue>
#include <set>
#include <map>

using namespace std;

struct vert{
    int name;
};

int counter = 0;
int N, M;
int flagAnswer = 0;


vector <int> *G = new vector <int>[N];
vector <int> PATH;
bool *visited = new bool[N]();

map<int, vector<int> > tree;
map<int, int> vis;

void createEdge(int SOURCE, int DESTINATION){
    // G[SOURCE].push_back(DESTINATION);
    // G[DESTINATION].push_back(SOURCE);
    tree[SOURCE].push_back(DESTINATION);
}

void DFS(int vertex, vector <int> FINDER, vector <int> *G){
    deque <int> Q;

    visited[FINDER.front()] = true;
    Q.push_back(FINDER.front());
    FINDER.erase(FINDER.begin());
    

    // do {
    //     for (int i = 0; i <)
    // }
    // while (next_permutation(G->front(), G->back()))

    // while (!Q.empty() && !FINDER.empty()){
    //     int current = Q.back();
    //     int next = FINDER.front();
    // }

}


bool valid_bfs(vector<int>& v)
{
    int n = (int)v.size();
    queue<set<int> > q;
    set<int> s;
    s.insert(1);

    q.push(s);
    int i = 0;
 
    while (!q.empty() && i < n)
    {

        if (vis.count(v[i])) return 0;
        vis[v[i]] = 1;
 
        if (q.front().size() == 0) q.pop();

        if (q.front().find(v[i]) == q.front().end()) return 0;
        s.clear();
 

        for (auto j : tree[v[i]]) {
            if (vis.count(j)) {
                continue;
            }
            s.insert(j);
        }

        if (s.size() > 0) {
            set<int> temp = s;
            q.push(temp);
        }
        s.clear();
 
        q.front().erase(v[i]);
 
        i++;
    }
    flagAnswer = 1;
    return 1;
}
int main() {
    cin >> N >> M;
    
    vector <int> FINDER;
    
    for (int i = 0; i < N; i++){
        int x;
        cin >> x;
        FINDER.push_back({x});
        visited[i] = false;
    }

    for (int i = 0; i < M; i++){
        int x, y;
        cin >> x >> y;
        createEdge(x, y);
    }

    // DFS(1, FINDER, G);
    valid_bfs(FINDER);

    cout << flagAnswer;
    
    return 0;
}

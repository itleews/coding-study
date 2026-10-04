#include <iostream>
#include <vector>
using namespace std;

int n, m;
int visit = 0;

vector<vector<int>> graph;
vector<bool> visited;

void DFS(int cur)
{
    visited[cur] = true;
    visit++;

    for (int next : graph[cur])
    {
        if (visited[next])
            continue;

        DFS(next);
    }
}

int main()
{
    cin >> n >> m;

    graph.resize(n + 1);
    visited.resize(n + 1, false);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    DFS(1);

    cout << visit - 1;

    return 0;
}
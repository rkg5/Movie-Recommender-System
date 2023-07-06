#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) x.begin(), x.end()
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

int ans = 0;
vector<int> adj[100005];
int n, m, cnt[100005], visited[100005];
vector<int> temp;

void solve(int u)
{
    temp.push_back(u);
    visited[u] = 1;
    for (auto v : adj[u])
    {
        if (!visited[v])
        {
            solve(v);
        }
    }
}

signed main()
{
    IOS;
    cin >> n >> m;
    int u, v;
    while (m--)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        cnt[u]++;
        cnt[v]++;
    }

    memset(visited, 0, sizeof(visited));

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            temp.clear();
            solve(i);

            bool check = true;
            for (auto x : temp)
            {
                check &= (cnt[x] == 2);
            }

            if (check)
            {
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}

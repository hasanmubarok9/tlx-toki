#include <bits/stdc++.h>

using namespace std;

const int N = 505;
const int INF = 1e9;
vector<pair<int, int>> vec[N];
int dist[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			dist[i] = INF;
			vec[i].clear();
		}
		for (int i = 0; i < m; i++)
		{
			int u, v, w;
			cin >> u >> v >> w;
			vec[u].emplace_back(v, w);
		}
		dist[0] = 0;
		bool updated = false;
		for (int i = 0; i < n; i++)
		{
			updated = false;
			for (int j = 0; j < n; j++)
			{
				for (int k = 0; k < vec[j].size(); k++)
				{
					int a = j;
					int b = vec[j][k].first;
					int w = vec[j][k].second;
					if (dist[a] == INF) continue;
					if (dist[a] + w < dist[b])
					{
						dist[b] = dist[a] + w;
						updated = true;
					}
				}
			}
		}
		if (updated)
		{
			cout << "Pak Dengklek tidak mau pulang" << '\n';
		}
		else if (dist[n - 1] == INF)
		{
			cout << "Tidak ada jalan" << '\n';
		}
		else
		{
			cout << dist[n - 1] << '\n';
		}
	}
	return 0;
}

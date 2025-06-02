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
		int v, e;
		cin >> v >> e;

		for (int i = 0; i < v; ++i)
		{
			dist[i] = INF;
			vec[i].clear();
		}
		for (int i = 0; i < e; i++)
		{
			int x, y, z;
			cin >> x >> y >> z;
			vec[x].emplace_back(y, z);
		}

		dist[0] = 0;
		bool updated;
		for (int i = 0; i < v; i++)
		{
			updated = false;
			for (int j = 0; j < v; j++)
			{
				for (int k = 0; k < vec[j].size(); k++)
				{
					int a = j;
					int b = vec[j][k].first;
					int cost = vec[j][k].second;
					if (dist[a] == INF) continue;
					if (dist[a] + cost < dist[b])
					{
						dist[b] = dist[a] + cost;
						updated = true;
					}
				}
			}
		}
		if (updated)
		{
			cout << "Pak Dengklek tidak mau pulang\n";
		}
		else if (dist[v - 1] == INF)
		{
			cout << "Tidak ada jalan" << '\n';
		}
		else
		{
			cout << dist[v - 1] << '\n';
		}

	}

	return 0;
}

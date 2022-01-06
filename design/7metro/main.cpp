#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#define NONE -1

using namespace std;

struct Edge{
	int v1;
	int v2;
	int weight;

	Edge(int v1In, int v2In, int weightIn): v1(v1In), v2(v2In), weight(weightIn){}

	bool operator<(const Edge& e)
	{
		return weight < e.weight;
	}
};

int findRoot(int fa[], int v)
{
	if (fa[v] == NONE)
		return v;
	else
		return fa[v] = findRoot(fa, fa[v]);
}

int N, M;
int main()
{
	cin >> N >> M;
	vector<Edge> edges;

	int v1, v2, weight;
	for (int i = 1; i <= M; i++)
	{
		cin >> v1 >> v2 >> weight;
		edges.push_back(Edge(v1, v2, weight));
	}

	int father[N+1];
	memset(father, NONE, sizeof(father));//并查集初始化

	sort(edges.begin(), edges.end());//按照施工天数从小到大排序

	//模拟施工过程
	for (int i = 0; i < M; i++)
	{
		//归并两棵子树
		father[findRoot(father, edges[i].v1)] = findRoot(father, edges[i].v2);

		if (findRoot(father, 1) == findRoot(father, N))
		{
			cout << edges[i].weight;
			return 0;
		}
	}
}

/*
input sample1:
6 6
1 2 4
2 3 4
3 6 7
1 4 2
4 5 5
5 6 6

output sample1:
6

input sample2:

output sample2:

input sample3:

output sample3:

*/
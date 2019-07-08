#pragma once

#include<iostream> 
#include<iterator>
#include<vector>
#include<list>
#include<queue>
#include<fstream>
#include<algorithm>

using namespace std;

struct edge
{
  int nextNode{};
  int cost{};
};

vector<int> Dijkstra(const vector<list<edge>>& graph, int initialNode)
{
  vector<int> costs(graph.size(), numeric_limits<int>::max());
  costs[initialNode] = 0;

  vector<bool> visited(graph.size(), false);

  priority_queue<int> heap;
  heap.push(initialNode);

  while (!heap.empty())
  {
    auto node = heap.top();
    heap.pop();

    for (const auto& edge : graph.at(node))
    {
      if (costs[node] + edge.cost < costs[edge.nextNode])
      {
        costs[edge.nextNode] = costs[node] + edge.cost;

        if (!visited[edge.nextNode])
        {
          visited[edge.nextNode] = true;
          heap.push(edge.nextNode);
        }
      }
    }
  }

  return costs;
}

void RunDijkstra()
{
  // read input data
  ifstream in("dijkstra.in");

  int nodesCount{};
  int edgesCount{};

  in >> nodesCount;
  in >> edgesCount;

  vector<list<edge>> graph(nodesCount + 1, list<edge>{});
  for (int i = 0; i < edgesCount; ++i)
  {
    int from{}, to{}, cost{};
    in >> from >> to >> cost;

    graph[from].push_back({ to, cost });
    //graph[to].push_back({from, cost});
  }

  // run dijkstra
  auto costs = Dijkstra(graph, 1);

  // write output data
  ofstream out("dijkstra.out");
  for (size_t i = 2; i < costs.size(); ++i)
  {
    if (costs[i] == numeric_limits<int>::max())
      out << "0 ";
    else
      out << costs[i] << " ";
  }
}

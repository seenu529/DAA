#include <iostream>
using namespace std;

#define INF 9999
#define V 5

void prim(int graph[V][V])
{
    int selected[V] = {0};
    int edges = 0;
    int totalCost = 0;

    selected[0] = 1;

    cout << "Edges in Minimum Spanning Tree:\n";

    while (edges < V - 1)
    {
        int min = INF;
        int x = 0, y = 0;

        for (int i = 0; i < V; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < V; j++)
                {
                    if (!selected[j] && graph[i][j] < min && graph[i][j] != 0)
                    {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        cout << x << " - " << y << " : " << graph[x][y] << endl;

        totalCost += graph[x][y];
        selected[y] = 1;
        edges++;
    }

    cout << "Minimum Cost = " << totalCost << endl;
}

int main()
{
    int graph[V][V] =
    {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    prim(graph);

    return 0;
}

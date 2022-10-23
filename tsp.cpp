#include <bits/stdc++.h>
using namespace std;
#define V 4

int path[V];

void travllingSalesmanProblem(int graph[][V], int s)
{
    vector<int> vertex;
    for (int i = 0; i < V; i++)
        if (i != s)
            vertex.push_back(i);
 
    int min_path = INT_MAX;
    do {
        int current_pathweight = 0;
        int k = s;
        for (int i = 0; i < vertex.size(); i++) {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
            path[i + 1] = k;
        }
        current_pathweight += graph[k][s];
 
        // update minimum
        min_path = min(min_path, current_pathweight);
 
    } while (
        next_permutation(vertex.begin(), vertex.end()));
}
int main()
{
    int graph[][V] = { { 0, 10, 15, 20 },
                       { 10, 0, 35, 25 },
                       { 15, 35, 0, 30 },
                       { 20, 25, 30, 0 }};
    int s = 0;
    travllingSalesmanProblem(graph, s);
    for (int i = 0 ; i < 4 ; i++)
    {
        cout << path[i] + 1;
        if (!(i + 1 == 4))
            cout << "-->";
        else
            cout << "-->1";
    }
    return 0;
}
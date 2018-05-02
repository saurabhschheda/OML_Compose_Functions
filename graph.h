#ifndef GRAPH_H
#define GRAPH_H

#include <cfloat>
#include <vector>

using namespace std;

vector< vector<double> > getVector(const int size, const double *data)
{
    vector< vector<double> > graph(size);
    for (int i = 0; i < size; ++i)
    {
		vector<double> row(size);
        for (int j = 0; j < size; ++j)
        {
            row[j] = *(data + (i * size) + j);
        }
        graph[i].assign(row.begin(), row.end());
    }
    return graph;
}

// A utility function to find the vertex with minimum distance value, from the 
// set of vertices not yet finalized
int nearestNode(vector<double> dist, vector<bool> finalized) 
{
    double min = DBL_MAX;
    int minIndex;

    for (int i = 0; i < dist.size(); ++i)
    {
        if (!finalized[i] && dist[i] <= min)
        {
            min = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

double* getDoublePointer(vector<double> result)
{
	double *distances = new double[result.size()];
	for (int i = 0; i < result.size(); ++i)
	{
		*(distances + i) = result[i];
	}
	return distances;
}

double* dijkstra(vector< vector<double> > graph, int src) 
{
    int size = graph.size();
	vector<double> dist;
    vector<bool> finalized (size, 0);
    // finalized[i] will be 1 if shortest distance from src to i is finalized
	dist.assign(size, DBL_MAX);
	dist[src] = 0.0;
    
    for (int count = 0; count < size-1; count++) 
    {
        int currentNode = nearestNode(dist, finalized);
        finalized[currentNode] = 1;
        for (int node = 0; node < size; node++)
        {
            if 
            (
                !finalized[node] &&
                graph[currentNode][node] &&
                dist[currentNode] != DBL_MAX &&
                dist[currentNode] + graph[currentNode][node] < dist[node]
            ) {
                dist[node] = dist[currentNode] + graph[currentNode][node];
            }
        }
    }

    return getDoublePointer(dist);
}

#endif
/*
---> Friendliest person <---

In a social network, the 'friendliness' of a user p is given by

(number of friends) + 1/2 (number of friends of friends) 
+ 1/3 (num friends of friends of friends) + 1/4 ...

That is,
                   ∞
friendliness(p) =  Σ  (1/n) * (num users u where length of shortest path p to u = n)
                  n=1

You should use doubles when calculating the friendliness of a user.

Write the function friendliestPerson(Graph g, int p), which takes an undirected Graph
representing a social network and returns the friendliness of the user p.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"

double friendliness(Graph g, int p) {
    double res = 0;

    bool *visited = calloc(GraphNumVertices(g), sizeof(bool));
    int *dist = calloc(GraphNumVertices(g), sizeof(int));

    Queue q = QueueNew();

    QueueEnqueue(q, p);
    visited[p] = true;
    dist[p] = 0;
    while (!QueueIsEmpty(q)) {
        int v = QueueDequeue(q);

        if (dist[v] > 0) {
            res += 1.0 / dist[v];
        }

        for (int w = 0; w < GraphNumVertices(g); w++) {
            if (GraphIsAdjacent(g, v, w) && !visited[w]) {
                QueueEnqueue(q, w);
                visited[w] = true;
                dist[w] = dist[v] + 1;
            }
        }
    }

    QueueFree(q);
    free(visited);
    free(dist);

    return res;
}

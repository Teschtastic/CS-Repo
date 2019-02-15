//
//  main.cpp
//  Dijkstra
//
//  Created by Sean Tesch on 11/14/17.
//  Copyright © 2017 Sean Tesch. All rights reserved.

#include <stdio.h>
#include <limits.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{
    string filename;
    cout << "Enter a filename: " << endl;
    cin >> filename;
    ifstream file(filename);
    
    if (!file.good())
    {
        cout << "ERROR: Unable to open input file " << filename << endl;
        
    }
    
    int x;
    file >> x;
    #define V x
    int graph[V][V];
   // cout << V << endl;
    x *= x;
    string strGraph[x];
    
    //cout << V << endl;
    if (file.is_open())
    {
        for (int i = 0; i < x; i++)
        {
            //file >> strGraph[i];
            file >> graph[(i+1)%5][i];
            if (graph[(i+1)%5][i] == -1)
                graph[(i+1)%5][i] = 0;
           cout << graph[(i+1)%5][i] << endl;
        }
    
   // cout << graph[1][0] << endl;
   // cout << graph[1][1] << endl;
   // cout << graph[1][2] << endl;
    
    
    // Initialize min value
    int min = INT_MAX, min_index = 0;
    int dist[V];    // distance array
    bool sptSet[V]; // shortest path array

    for (int i = 0; i < V; i++) // sets everything to base case
    {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    
    dist[0] = 0; // sets starting space to the 0
    
    for (int count = 0; count < V-1; count++)
    {
        
        for (int v = 0; v < V; v++)
        {
            if (sptSet[v] == false && dist[v] <= min) // changes the min to the array elemt if it's less than min
            {
                min = dist[v];
                min_index = v;
            }
        }
        
        int u = min_index;
        
        sptSet[u] = true;
        
        for (int v = 0; v < V; v++)
        {
            // if dist v isn't in the set, and there is an edge from u to v, and the the path from u to v is smaller than the value in dist already
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v]; // update the distance already to the distance plus the new distance
         }
    }
        
/*
    cout << "Vertex   Distance from Source " << endl;
    for (int i = 0; i < V; i++)
    cout << i << "\t\t" << dist[i] << endl;
*/
    }
    return 0;
}


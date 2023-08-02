#include<stdio.h>
#include<stdlib.h>

#define MAX 100
#define INT_MAX 10000

int n;
int dist[MAX];
int sptSet[MAX];
int adj[MAX][MAX];


void createGraph(){
    int max, origin, dest, weight;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    max = n * (n - 1);
    for(int i = 1; i <= max; ++i){
        printf("Enter the edge %d and it weight (-1 -1 to quit): ", i);
        scanf("%d %d %d", &origin, &dest, &weight);
        if(origin == -1 && dest == -1){
            break;
        }
        if(origin >= n || dest >= n || origin < 0 || dest < 0){
            printf("Invalid edge!\n");
            i--;
        }
        else{
            adj[origin][dest] = weight;
        }
    }
}

void printShortestPath(){
    printf("Vertex \t\t Distance from source\n");
    for(int i = 0; i < n; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

int minDistance(){
    int min = INT_MAX, minIndex;
    for(int v = 0; v < n; v++){
        if(sptSet[v] == 0 && dist[v] < min){
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void dijsktra(int n, int src){
    for(int v = 0; v < n; v++){
        dist[v] = INT_MAX;
        sptSet[v] = 0;
    }
    dist[src] = 0;
    for(int i = 0; i < n - 1; ++i){
        int u = minDistance();
        sptSet[u] = 1;
        for(int v = 0; v < n; v++){
            if(!sptSet[v] && adj[u][v] && dist[u] != INT_MAX && dist[u] + adj[u][v] < dist[v])
                dist[v] = dist[u] + adj[u][v];
        }
    }
    printShortestPath();
}

int main(){
    int src;
    createGraph();
    printf("Enter the source:\n");
    scanf("%d", &src);
    dijsktra(n, src);
    printShortestPath();
    return 0;
}

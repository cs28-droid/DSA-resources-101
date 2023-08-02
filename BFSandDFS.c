#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int n;
int adj[MAX][MAX];
int state[MAX];
void createGraph();

void DF_Traversal();
void DFS(int v);

int queue[MAX], front = -1, rear = -1;
void enqueue(int vertex);
int dequeue();
bool isQueueEmpty();
void BF_Traversal();
void BFS(int v);

// -------------DFS-------------------

void DF_Traversal(){
    int v;
    for(int i = 0; i < n; ++i)
        state[i] = 0;  //initial state
    printf("Enter the starting vertex: ");
    scanf("%d", &v);
    printf("DFS traversal of the given graph is:\n");
    DFS(v);
}

void DFS(int v){
    state[v] = 1;    //visited
    printf("%d ", v);
    for(int i = 0; i < n; ++i){
        if(!state[i] && adj[v][i] == 1)
            DFS(i);
    }
}

// -------------DFS-------------------



// --------------BFS--------------------

void enqueue(int vertex){
    if(rear == MAX - 1)
        printf("Queue overflow!\n");
    else{
        if(front == -1)
            front++;
        queue[++rear] = vertex;
    }
}

int dequeue(){
    if(front > rear || front == -1){
        printf("Queue underflow!\n");
        exit(1);
    }
    else{
        int deleteItem = queue[front];
        front++;
        return deleteItem;
    }
}

bool isQueueEmpty(){
    if(front == -1 || front > rear)
        return true;
    return false;
}

void BF_Traversal(){
    int v;
    for(int i = 0; i < n; ++i)
        state[i] = 0;  //initial state
    printf("Enter the starting vertex: ");
    scanf("%d", &v);
    printf("BFS traversal of the given graph is:\n");
    BFS(v);
}

void BFS(int v){
    enqueue(v);
    state[v] = 1; //waiting state
    while(!isQueueEmpty()){
        v = dequeue();
        printf("%d ", v);
        state[v] = 2;     //visited
        for(int i = 0; i < n; i++){
            if(adj[v][i] == 1 && state[i] == 0){
                enqueue(i);
                state[i] = 1;
            }
        }
    }
    printf("\n");
}

// --------------BFS--------------------


// -------------Create Graph--------------

void createGraph(){
    int max, origin, dest;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    max = n * (n - 1);
    for(int i = 1; i <= max; ++i){
        printf("Enter the edge %d (-1 -1 to quit): ", i);
        scanf("%d %d", &origin, &dest);
        if(origin == -1 && dest == -1){
            break;
        }
        if(origin >= n || dest >= n || origin < 0 || dest < 0){
            printf("Invalid edge!\n");
            i--;
        }
        else{
            adj[origin][dest] = 1;
        }
    }
}

// -------------Create Graph--------------

int main(){
    int choice;
    printf("Enter a graph\n");
    createGraph();
    while(1){
        printf("Enter the traversal method (1 for DFS and 2 for BFS)\n");
        printf("Enter 3 to exit\n");
        scanf("%d", &choice);
        if(choice == 1){
            DF_Traversal();
        }
        else if(choice == 2){
            BF_Traversal();
        }
        else{
            exit(1);
        }
    }

    return 0;
}

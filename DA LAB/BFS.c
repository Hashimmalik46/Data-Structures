#include <stdio.h>

#define SIZE 5

int graph[SIZE][SIZE] = {
    {0, 1, 0, 1, 0},
    {1, 0, 0, 0, 1},
    {1, 0, 0, 1, 1},
    {0, 1, 1, 0, 1},
    {0, 0, 1, 1, 0}
};

int visited[SIZE] = {0};
int queue[SIZE], front = 0, rear = 0;

void enqueue(int v) {
    queue[rear++] = v;
}

int dequeue() {
    return queue[front++];
}

void bfs(int start) {
    enqueue(start);
    visited[start] = 1;

    while (front < rear) {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < SIZE; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    printf("BFS starting from node 0:\n");
    bfs(0);
    return 0;
}

#include <stdio.h>
#include <stdbool.h>

#define MAX 1000

int graph[MAX][MAX];
int neighbors[MAX]; // хэдэн хөрштэйг хадгална

int check[MAX]; // 0 = очоогүй, 1 = DFS дотор, 2 = дууссан
int n, m;

// ирмэг нэмэх функц
void addEdge(int u, int v) {
    graph[u][neighbors[u]] = v;
    neighbors[u]++;
}


bool dfs(int v) {
    check[v] = 1; // DFS дотор байгаа 
    for(int i = 0; i < neighbors[v]; i++) {
        int u = graph[v][i];
        // хэрвээ u дээр DFS дотор байгаа бол цикл байна
        if(check[u] == 1) {
            return true;
        }
        // u дээр очоогүй бол DFS-г үргэлжлүүлнэ
        if(check[u] == 0) {
            if(dfs(u)) { 
                return true; 
            }
        }
    }
    check[v] = 2; // DFS дууссан тул 2 болгоно
    return false;
}

int main() {
    n = 10;

    for(int i = 0; i < n; i++) {
        neighbors[i] = 0;
        check[i] = 0;
    }

    addEdge(0, 1);
    addEdge(0, 9);
    addEdge(0, 6);
    addEdge(1, 3);
    addEdge(9, 3);
    addEdge(9, 6);
    addEdge(6, 4);
    addEdge(6, 5);
    addEdge(4, 5);
    addEdge(4, 8);
    addEdge(5, 7);
    addEdge(5, 8);
    addEdge(7, 2);
    addEdge(7, 8);
    addEdge(8, 4);

    bool cycle = false;

    for(int i = 0; i < n; i++) {
        if(check[i] == 0) {
            if(dfs(i)) {
                cycle = true;
                break;
            }
        }
    }

    if(cycle)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}

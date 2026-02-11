#include <stdio.h>

#define MAXN 1000

int a[MAXN][MAXN];
int dp[MAXN][MAXN];
int parent_i[MAXN][MAXN];
int parent_j[MAXN][MAXN];

int main() {
    int n;
    scanf("%d", &n);

    // Read matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // DP start
    dp[0][0] = a[0][0];
    parent_i[0][0] = -1;
    parent_j[0][0] = -1;

    // First row
    for(int j = 1; j < n; j++) {
        dp[0][j] = dp[0][j-1] + a[0][j];
        parent_i[0][j] = 0;
        parent_j[0][j] = j-1;
    }

    // First column
    for(int i = 1; i < n; i++) {
        dp[i][0] = dp[i-1][0] + a[i][0];
        parent_i[i][0] = i-1;
        parent_j[i][0] = 0;
    }

    // Fill rest
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n; j++) {
            if(dp[i-1][j] > dp[i][j-1]) {
                dp[i][j] = dp[i-1][j] + a[i][j];
                parent_i[i][j] = i-1;
                parent_j[i][j] = j;
            } else {
                dp[i][j] = dp[i][j-1] + a[i][j];
                parent_i[i][j] = i;
                parent_j[i][j] = j-1;
            }
        }
    }

    printf("Max value: %d\n", dp[n-1][n-1]);

    // Reconstruct path
    int mark[MAXN][MAXN] = {0};
    int i = n-1, j = n-1;

    while(i != -1 && j != -1) {
        mark[i][j] = 1;
        int pi = parent_i[i][j];
        int pj = parent_j[i][j];
        i = pi;
        j = pj;
    }

    // Print matrix with path
    printf("Path:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(mark[i][j])
                printf("*%2d ", a[i][j]);
            else
                printf(" %2d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
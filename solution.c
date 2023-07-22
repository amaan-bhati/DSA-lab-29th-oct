#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to calculate the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to calculate the maximum possible total points
int calculateMaxPoints(int N, int K, int *A) {
    int *dp = (int *)malloc((N + 1) * sizeof(int));

    // Initialize the dp array with minimum integer value
    for (int i = 0; i <= N; i++) {
        dp[i] = INT_MIN;
    }

    dp[N] = 0; // Base case

    for (int i = N - 1; i >= 0; i--) {
        for (int j = i + 1; j <= N && j <= i + K; j++) {
            dp[i] = max(dp[i], A[i] + dp[j]);
        }
    }

    int maxPoints = dp[0];
    free(dp);
    return maxPoints;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, K;
        scanf("%d %d", &N, &K);

        int *A = (int *)malloc(N * sizeof(int));
        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
        }

        int result = calculateMaxPoints(N, K, A);
        printf("%d\n", result);

        free(A);
    }

    return 0;
}

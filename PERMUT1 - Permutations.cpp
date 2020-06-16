#include <stdio.h>

int dp[100][100];

int inversions(int n, int k)
{
    if (dp[n][k] != -1) return dp[n][k];
    if (k == 0) return dp[n][k] = 1; // si la inversion es igual a 0, el resultado sera 1
    if (n == 0) return dp[n][k] = 0;// si nuestros elementos son 0, el resultado sera 0 
    int j = 0, val = 0;
    for (j = 0; j < n && k-j >= 0; j++)
        val += inversions(n-1, k-j); //uso de recursividad 
    return dp[n][k] = val;
}

int main()
{
    int t; //numero de casos 
    scanf("%d", &t); 
    while (t--)
	{
        int n, k, i, j;
        scanf("%d%d", &n, &k);
        for (i = 1; i <= n; i++)
            for (j = 0; j <= k; j++)
                dp[i][j] = 1; //para asegurarnos que dp[1][0] == 1
        printf("%d\n", inversions(n, k));
    }
    
    return 0;
}

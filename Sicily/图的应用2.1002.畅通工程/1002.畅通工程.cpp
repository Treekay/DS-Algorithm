#include<cstdio>  
#include<iostream>  
using namespace std;  
#define inf 9999999  
int map[250][250];  
int n, m;  
int Floyd(int x, int y) {  
    int t, i, j;  
    for (t = 0; t < n; t++)  
        for (i = 0; i < n; i++)  
            for (j = 0; j < n; j++)  
                if (map[i][j] > map[i][t] + map[t][j]) {  
                    map[i][j] = map[i][t] + map[t][j];  
                }  
    if (map[x][y] == inf)  
        return -1;  
    else  
        return map[x][y];  
}  
int main() {  
    while (scanf("%d%d", &n, &m) != EOF) {  
        int start, end, weight, qStart, qEnd;  
        for (int i = 0; i <=n; i++)  
            for (int j = 0; j <=n; j++)  
                map[i][j] = map[j][i] = inf;  
        for (int i = 0; i < n; i++)  
            map[i][i] = 0;  
        for (int i = 0; i < m; i++) {  
            scanf("%d%d%d", &start, &end, &weight);  
            if (map[start][end] > weight)  
                map[start][end] = map[end][start] = weight;  
        }  
        scanf("%d%d", &qStart, &qEnd);  
        printf("%d\n", Floyd(qStart, qEnd));  
    }  
}
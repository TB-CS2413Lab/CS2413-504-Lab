#include <stdio.h>
#include <stdlib.h>

#define ROWS 5    
#define COLS 5    

void dfs(int grid[ROWS][COLS], int visited[ROWS][COLS], int i, int j, int rows, int cols) {
    if (i < 0 || i >= rows || j < 0 || j >= cols) return; 
    if (grid[i][j] == 0 || visited[i][j]) return;         

    
    visited[i][j] = 1;

    dfs(grid, visited, i + 1, j, rows, cols); 
    dfs(grid, visited, i - 1, j, rows, cols); 
    dfs(grid, visited, i, j + 1, rows, cols); 
    dfs(grid, visited, i, j - 1, rows, cols); 
}

int countIslands(int grid[ROWS][COLS], int rows, int cols) 
{
    int visited[ROWS][COLS] = {0}; 
    int count = 0;

    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            if (grid[i][j] == 1 && !visited[i][j]) 
            {
                dfs(grid, visited, i, j, rows, cols);
                count++; 
            }
        }
    }
    return count;
}

int main() {
    int grid[ROWS][COLS] = 
    {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 1},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0}
    };

    printf("Grid entered:\n");
    for (int i = 0; i < ROWS; i++) 
    {
        for (int j = 0; j < COLS; j++) 
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    int islands = countIslands(grid, ROWS, COLS);
    printf("\nNumber of islands: %d\n", islands);

    return 0;
}
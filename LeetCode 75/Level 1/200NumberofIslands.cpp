#include <bits/stdc++.h>
using namespace std;

//*** Submittable code starts ***//
class Solution
{
    void decompressor(vector<vector<char>> &grid, int i, int j)
    {
        if (i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || grid[i][j] != '1')
            return;
        grid[i][j] = '0';
        decompressor(grid, i + 1, j);
        decompressor(grid, i - 1, j);
        decompressor(grid, i, j - 1);
        decompressor(grid, i, j + 1);
    }
//*** Submittable code ends ***//
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int ct = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    decompressor(grid, i, j);
                    ct++;
                }
            }
        }
        return ct;
    }
};

int main()
{
    vector<vector<char>> grid = {{'1', '1', '0', '0', '0'},
                                 {'1', '1', '0', '0', '0'},
                                 {'0', '0', '1', '0', '0'},
                                 {'0', '0', '0', '1', '1'}};
    Solution sol;
    cout << "Result: " << sol.numIslands(grid) << "\n";
    return 0;
}
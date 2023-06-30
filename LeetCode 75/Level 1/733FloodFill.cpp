#include <bits/stdc++.h>
using namespace std;

//***Driver code start***//
class Solution {
private:
    void coloring(vector<vector<int>>& image, int sr, int sc, int color, int srcColor){
        if( sr < 0 || sr == image.size() || sc < 0 || sc == image[0].size() || image[sr][sc] == color || image[sr][sc] != srcColor )
            return;
        image[sr][sc] = color;
        coloring( image, sr-1, sc, color, srcColor);
        coloring( image, sr+1, sc, color, srcColor);
        coloring( image, sr, sc-1, color, srcColor);
        coloring( image, sr, sc+1, color, srcColor);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int srcColor = image[sr][sc];
        coloring( image, sr, sc, color, srcColor);
        return image;
    }
    
};
//***Driver code end***//

int main(){
    int m, n;
    cin >> m >> n;
    Solution sol;
    image = sol.floodFill(image, 1, 1, 2);
    cout << "Resulting grid:\n";
    for( auto i : image ){
        for( auto j : i ){
            cout << j <<' ';
        }
        cout << "\n";
    }
}
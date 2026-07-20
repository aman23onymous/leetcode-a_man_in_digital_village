class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();
        vector<int> a;
        k=k%(n*m);
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) a.push_back(grid[i][j]);
        reverse(begin(a),begin(a)+n*m-k);
        reverse(begin(a)+n*m-k,end(a));
        reverse(begin(a),end(a));
        for(int i=0;i<n*m;i++) for(int j=0;j<m;j++) grid[i/m][i%m]=a[i];
        return grid;
    }
};
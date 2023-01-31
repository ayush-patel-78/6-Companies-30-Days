// https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/description/

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> preSums(m + 1, vector<vector<int>>(n + 2, {0, 0}));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                preSums[i + 1][j + 1][0] = preSums[i][j][0] + grid[i][j];
                if (j - 1 >= 0) {
                    preSums[i + 1][j - 1][1] = preSums[i][j][1] + grid[i][j];
                }
            }
        }
        set<int> bTree;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bTree.insert(grid[i][j]);
                if (bTree.size() > 3) {
                    bTree.erase(bTree.begin());
                }
                for (int l = 1; (i + 2 * l < m) && (j - l >= 0) && (j + l < n); l++) {
                    int sum = -grid[i][j] + grid[i + 2 * l][j];  //deduplicate
                    sum += preSums[i + l][j - l][1] - preSums[i][j][1];  //upper left
                    sum += preSums[i + l][j + l][0] - preSums[i][j][0];  //upper right
                    sum += preSums[i + 2 * l][j][0] - preSums[i + l][j - l][0];  //lower left
                    sum += preSums[i + 2 * l][j][1] - preSums[i + l][j + l][1];  //lower right
                    bTree.insert(sum);
                    if (bTree.size() > 3) {
                        bTree.erase(bTree.begin());
                    }
                }
            }
        }
        vector<int> result;
        for (int num : bTree) {
            result.push_back(num);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
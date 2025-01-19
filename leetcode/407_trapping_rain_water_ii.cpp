#include <iostream>
#include <vector>

using namespace std;

typedef std::vector<int> vInt;
typedef std::vector<vInt> vvInt;
class Solution {
  public:
    static int trapRainWater(const vvInt &heightMap) noexcept {
        // if (heightMap.size() < 3)
        //     return 0;
        //
        // vvInt mark(201, {201, 0});
        //
        // for (int i{1}; i < heightMap.size() - 1; ++i) {
        //     for (int j{1}; j < heightMap[i].size() - 1; ++j) {
        //         priority_queue<int> height;
        //         int y{i}, x{j};
        //         int upY{y};
        //         while (upY) {
        //             height.push(heightMap[--upY][x]);
        //         }
        //         int downY{y};
        //         while (downY != heightMap.size() - 1) {
        //             height.push(heightMap[++downY][x]);
        //         }
        //         int leftX{x};
        //         while (leftX) {
        //             height.push(heightMap[y][--leftX]);
        //         }
        //         int rightX{x};
        //         while (rightX != heightMap[y].size() - 1) {
        //             height.push(heightMap[y][++rightX]);
        //         }
        //         while (!height.empty()) {
        //             cout << height.top() << ' ';
        //             height.pop();
        //         }
        //         cout.put('\n');
        //     }
        // }
        //
        // int ans{};
        return solve(heightMap);
    }
    static int solve(const vvInt &heightMap) noexcept {
        // Direction arrays
        int dRow[4] = {0, 0, -1, 1};
        int dCol[4] = {-1, 1, 0, 0};

        int numOfRows = heightMap.size();
        int numOfCols = heightMap[0].size();

        vector<vector<bool>> visited(numOfRows, vector<bool>(numOfCols, false));

        // Priority queue (min-heap) to process boundary cells in increasing
        // height order
        priority_queue<Cell> boundary;

        // Add the first and last column cells to the boundary and mark them as
        // visited
        for (int i = 0; i < numOfRows; i++) {
            boundary.push(Cell(heightMap[i][0], i, 0));
            boundary.push(Cell(heightMap[i][numOfCols - 1], i, numOfCols - 1));
            // Mark left and right boundary cells as visited
            visited[i][0] = visited[i][numOfCols - 1] = true;
        }

        // Add the first and last row cells to the boundary and mark them as
        // visited
        for (int i = 0; i < numOfCols; i++) {
            boundary.push(Cell(heightMap[0][i], 0, i));
            boundary.push(Cell(heightMap[numOfRows - 1][i], numOfRows - 1, i));
            // Mark top and bottom boundary cells as visited
            visited[0][i] = visited[numOfRows - 1][i] = true;
        }

        int totalWaterVolume = 0;

        while (!boundary.empty()) {
            // Pop the cell with the smallest height from the boundary
            Cell currentCell = boundary.top();
            boundary.pop();

            int currentRow = currentCell.row;
            int currentCol = currentCell.col;
            int minBoundaryHeight = currentCell.height;

            // Explore all 4 neighboring cells
            for (int direction = 0; direction < 4; direction++) {
                int neighborRow = currentRow + dRow[direction];
                int neighborCol = currentCol + dCol[direction];

                // Check if the neighbor is within the grid bounds and not yet
                // visited
                if (isValidCell(neighborRow, neighborCol, numOfRows,
                                numOfCols) &&
                    !visited[neighborRow][neighborCol]) {
                    int neighborHeight = heightMap[neighborRow][neighborCol];

                    // If the neighbor's height is less than the current
                    // boundary height, water can be trapped
                    if (neighborHeight < minBoundaryHeight) {
                        totalWaterVolume += minBoundaryHeight - neighborHeight;
                    }

                    // Push the neighbor into the boundary with updated height
                    // (to prevent water leakage)
                    boundary.push(Cell(max(neighborHeight, minBoundaryHeight),
                                       neighborRow, neighborCol));
                    visited[neighborRow][neighborCol] = true;
                }
            }
        }

        return totalWaterVolume;
    }

  private:
    // Struct to store the height and coordinates of a cell in the grid
    class Cell {
      public:
        int height;
        int row;
        int col;

        // Constructor to initialize a cell
        Cell(int height, int row, int col)
            : height(height), row(row), col(col) {}

        // Overload the comparison operator to make the priority queue a
        // min-heap based on height
        bool operator<(const Cell &other) const {
            // Reverse comparison to simulate a min-heap
            return height >= other.height;
        }
    };

    // Helper function to check if a cell is valid (within grid bounds)
    static bool isValidCell(int row, int col, int numOfRows, int numOfCols) {
        return row >= 0 && col >= 0 && row < numOfRows && col < numOfCols;
    }
};

ostream &operator<<(ostream &out, const vvInt &matrix) noexcept {
    for (const vInt &row : matrix) {
        for (const int col : row)
            out << col << ' ';
        out.put('\n');
    }
    return out;
}

void test(const vvInt &heightMap, const int ans) noexcept {
    cout << heightMap;
    int myAns = Solution::trapRainWater(heightMap);
    cout << "ans: " << ans << " myAns: " << myAns << "\n\n";
}

int main() {
    test({{1, 4, 3, 1, 3, 2}, {3, 2, 1, 3, 2, 4}, {2, 3, 3, 2, 3, 1}}, 4);
    test({{3, 3, 3, 3, 3},
          {3, 2, 2, 2, 3},
          {3, 2, 1, 2, 3},
          {3, 2, 2, 2, 3},
          {3, 3, 3, 3, 3}},
         10);
}
/*
 * 1 4 3 1 3 2
 * 3 2 1 3 2 4
 * 2 3 3 2 3 1
 *
 * 0 0 0 0 0 0
 * 0 1 2 0 1 0
 * 0 0 0 0 0 0
 *
 * ---
 *
 * 1 4 3 1 3 2
 * 3 2 1 3 2 4
 * 2 3 2 2 3 1
 *
 * 0 0 0 0 0 0
 * 0 0 1 0 1 0
 * 0 0 0 0 0 0
 *
 * ---
 *
 * 3 3 3 3 3
 * 3 2 2 2 3
 * 3 2 1 2 3
 * 3 2 2 2 3
 * 3 3 3 3 3
 */

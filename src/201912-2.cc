#include <iostream>
#include <memory.h>

using namespace std;

#define MAX_LEN 1000000000

int main(int argc, char const* argv[])
{
    // Using ranged grid
    // Run-time error for (-MAX_LEN,-MAX_LEN) and (MAX_LEN,MAX_LEN)
    // int n;
    // cin >> n;
    // long long pos[n][2];
    // long long xMin, yMin, xMax, yMax;
    // xMin = yMin = MAX_LEN;
    // xMax = yMax = -MAX_LEN;
    // for (int i = 0; i < n; i++) {
    //     cin >> pos[i][0] >> pos[i][1];
    //     xMin = min(pos[i][0], xMin);
    //     yMin = min(pos[i][1], yMin);
    //     xMax = max(pos[i][0], xMax);
    //     yMax = max(pos[i][1], yMax);
    // }
    // int grid[xMax - xMin + 3][yMax - yMin + 3];
    // memset(grid, 0, sizeof(int) * (xMax - xMin + 3) * (yMax - yMin + 3));

    // for (int i = 0; i < n; i++) {
    //     pos[i][0] -= (xMin - 1);
    //     pos[i][1] -= (yMin - 1);
    //     grid[pos[i][0]][pos[i][1]] = 1;
    // }

    // int count[5] = { 0 };
    // for (int i = 0; i < n; i++) {
    //     // candidate point
    //     if (grid[pos[i][0]][pos[i][1] + 1]
    //         && grid[pos[i][0]][pos[i][1] - 1]
    //         && grid[pos[i][0] + 1][pos[i][1]]
    //         && grid[pos[i][0] - 1][pos[i][1]]) {
    //         int score = 0;
    //         // compute score
    //         score += grid[pos[i][0] - 1][pos[i][1] - 1];
    //         score += grid[pos[i][0] - 1][pos[i][1] + 1];
    //         score += grid[pos[i][0] + 1][pos[i][1] - 1];
    //         score += grid[pos[i][0] + 1][pos[i][1] + 1];
    //         count[score]++;
    //     }
    // }
    // for (int i = 0; i < 5; i++) {
    //     cout << count[i] << endl;
    // }

    // traverse those rubbishes
    int n;
    cin >> n;
    long long pos[n][2];
    for (int i = 0; i < n; i++) {
        cin >> pos[i][0] >> pos[i][1];
    }
    int count[5] = { 0 };
    for (int i = 0; i < n; i++) {
        int left = 0, right = 0, up = 0, down = 0;
        int leftUp = 0, leftDown = 0, rightUp = 0, rightDown = 0;
        for (int j = 0; j < n; j++) {
            int x = pos[j][0] - pos[i][0];
            int y = pos[j][1] - pos[i][1];

            if (make_pair(x, y) == make_pair(-1, 0)) {
                left = 1;
            } else if (make_pair(x, y) == make_pair(1, 0)) {
                right = 1;
            } else if (make_pair(x, y) == make_pair(0, 1)) {
                up = 1;
            } else if (make_pair(x, y) == make_pair(0, -1)) {
                down = 1;
            } else if (make_pair(x, y) == make_pair(-1, 1)) {
                leftUp = 1;
            } else if (make_pair(x, y) == make_pair(-1, -1)) {
                leftDown = 1;
            } else if (make_pair(x, y) == make_pair(1, 1)) {
                rightUp = 1;
            } else if (make_pair(x, y) == make_pair(1, -1)) {
                rightDown = 1;
            }
        }
        if (left && right && up && down) {
            int score = 0;
            score += leftUp;
            score += leftDown;
            score += rightUp;
            score += rightDown;
            count[score]++;
        }
    }
    for (int i = 0; i < 5; i++) {
        cout << count[i] << endl;
    }

    return 0;
}
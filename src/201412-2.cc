#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int matrix[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    int trace[2 * n - 1], order = 1;
    for (int i = 0; i < 2 * n - 1; i++)
    {
        trace[i] = i;
    }
    for (int i = 0; i < 2 * n - 1; i++)
    {
        if (order == 0)
        {
            for (int x = 0; x <= trace[i]; x++)
            {
                if (x >= n || trace[i] - x >= n)
                {
                    continue;
                }
                else
                {
                    cout << matrix[x][trace[i] - x] << " ";
                }
            }
            order = 1;
        }
        else if (order == 1)
        {
            for (int y = 0; y <= trace[i]; y++)
            {
                if (y >= n || trace[i] - y >= n)
                {
                    continue;
                }
                else
                {
                    cout << matrix[trace[i] - y][y] << " ";
                }
            }
            order = 0;
        }
    }
    // labyrinth, very hard to mimic
    // int pos[2] = {0, 0};
    // for (int i = 0; i < n * n; i++)
    // {
    //     cout << matrix[pos[0]][pos[1]] << " ";
    //     // cout << pos[0] << '\t' << pos[1] << endl;
    //     if (pos[0] == 0 && pos[1] % 2 == 0)
    //     {
    //         pos[1]++;
    //     }
    //     else if (pos[0] == 0 && pos[1] % 2 == 1)
    //     {
    //         pos[0]++;
    //         pos[1]--;
    //     }
    //     else if (pos[0] == n - 1 && pos[1] % 2 == 1)
    //     {
    //         pos[1]++;
    //     }
    //     else if (pos[0] == n - 1 && pos[1] % 2 == 0)
    //     {
    //         pos[0]--;
    //         pos[1]++;
    //     }
    //     else if (pos[1] == 0 && pos[0] % 2 == 1)
    //     {
    //         pos[0]++;
    //     }
    //     else if (pos[1] == 0 && pos[0] % 2 == 0)
    //     {
    //         pos[0]--;
    //         pos[1]++;
    //     }
    //     else if (pos[1] == n - 1 && pos[0] % 2 == 0)
    //     {
    //         pos[0]++;
    //     }
    //     else if (pos[1] == n - 1 && pos[0] % 2 == 1)
    //     {
    //         pos[0]++;
    //         pos[1]--;
    //     }
    //     else if ((pos[0] + pos[1]) % 2 == 0)
    //     {
    //         pos[0]--;
    //         pos[1]++;
    //     }
    //     else if ((pos[0] + pos[1]) % 2 == 1)
    //     {
    //         pos[0]++;
    //         pos[1]--;
    //     }
    // }
    cout << endl;

    return 0;
}
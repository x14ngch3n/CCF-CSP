#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    int board[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
    int newboard[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            newboard[i][j] = board[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // n in a row
            if (j != 0 && j != m - 1)
            {
                if (board[i][j - 1] == board[i][j] && board[i][j + 1] == board[i][j])
                {
                    for (int k = j - 1; k <= j + 1; k++)
                    {
                        newboard[i][k] = 0;
                    }
                }
            }
            // n in a column
            if (i != 0 && i != n - 1)
            {
                if (board[i - 1][j] == board[i][j] && board[i + 1][j] == board[i][j])
                {
                    for (int k = i - 1; k <= i + 1; k++)
                    {
                        newboard[k][j] = 0;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << newboard[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
#include <iostream>

using namespace std;

#define ROW 15
#define COL 10

int main(int argc, char const *argv[])
{
    int board[ROW + 8][COL] = {{0}};
    for (int i = 4; i < ROW + 4; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            cin >> board[i][j];
        }
    }
    int block[4][4];
    int lowOne;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> block[i][j];
            if (block[i][j] == 1)
            {
                lowOne = i;
            }
        }
    }
    int offset;
    cin >> offset;
    int depth = ROW + 3 - lowOne, flag = 1;
    for (int i = 0; i < ROW && flag; i++)
    {
        for (int j = 0; j < 4 && flag; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                if (block[j][k] && board[i + j][offset - 1 + k])
                {
                    depth = i - 1;
                    flag = 0;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (block[i][j])
            {
                board[depth + i][offset - 1 + j] = block[i][j];
            }
        }
    }

    for (int i = 4; i < ROW + 4; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int rectangle[4];
    int pixels[100][100] = {{0}};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> rectangle[j];
        }
        // draw the pixels within rectangle
        for (int x = rectangle[0]; x < rectangle[2]; x++)
        {
            for (int y = rectangle[1]; y < rectangle[3]; y++)
            {
                pixels[x][y] = 1;
            }
        }
    }
    int count = 0;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (pixels[i][j] == 1)
            {
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}
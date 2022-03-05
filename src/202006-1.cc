#include <iostream>

using namespace std;

#define LINE(i) (line[0] + dots[i][0] * line[1] + dots[i][1] * line[2])

string isLiner(long long dots[][3], int n, long long line[])
{
    for (int i = 0; i < n; i++)
        // cout << dots[i][2] << '\t' << LINE(i) << endl;
        if ((dots[i][2] == dots[0][2] && LINE(0) * LINE(i) < 0) || (dots[i][2] != dots[0][2] && LINE(0) * LINE(i) > 0))
            return "No";
    return "Yes";
}

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    // use long long to avoid overflow
    // input might be 2^20
    long long dots[n][3];
    long long lines[m][3];
    char tmp;
    for (int i = 0; i < n; i++)
    {
        // convert type(A/B) to int
        cin >> dots[i][0] >> dots[i][1] >> tmp;
        dots[i][2] = (long long)tmp;
    }
    for (int i = 0; i < m; i++)
        cin >> lines[i][0] >> lines[i][1] >> lines[i][2];

    for (int i = 0; i < m; i++)
        cout << isLiner(dots, n, lines[i]) << endl;
    return 0;
}
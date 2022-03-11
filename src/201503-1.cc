#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const* argv[])
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> pic(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> pic[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << pic[j][m - 1 - i] << " ";
        }
        cout << endl;
    }

    return 0;
}

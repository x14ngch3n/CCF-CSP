#include <iostream>

using namespace std;

int main(int argc, char const* argv[])
{
    int n, m, l;
    cin >> n >> m >> l;
    int pixels[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> pixels[i][j];
        }
    }
    int* grey = new int[l]();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            grey[pixels[i][j]]++;
        }
    }
    for (int i = 0; i < l; i++) {
        cout << grey[i] << " ";
    }
    cout << endl;
    return 0;
}
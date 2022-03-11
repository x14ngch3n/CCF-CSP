#include <iostream>

using namespace std;

int main(int argc, char const* argv[])
{
    int n, L, t;
    cin >> n >> L >> t;
    // position: balls[i][0]
    // direction: balls[i][1]: 1 for right, -1 for left
    int balls[n][2];
    for (int i = 0; i < n; i++) {
        cin >> balls[i][0];
        balls[i][1] = 1;
    }
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < n; j++) {
            balls[j][0] += balls[j][1];
            // change direction if reach end
            if (balls[j][0] == 0 || balls[j][0] == L) {
                balls[j][1] = -balls[j][1];
            }
        }
        for (int j = 0; j < n; j++) {
            for (int k = j; k < n; k++) {
                // change both direction if collide
                if (balls[j][0] == balls[k][0]) {
                    balls[j][1] = -balls[j][1];
                    balls[k][1] = -balls[k][1];
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << balls[i][0] << " ";
    }
    cout << endl;

    return 0;
}

#include <iostream>

using namespace std;

int predict(int theta, int results[][2])
{
    ;
}

int main(int argc, char const* argv[])
{
    int m;
    cin >> m;
    int results[m][2];
    for (int i = 0; i < m; i++) {
        cin >> results[i][0] >> results[i][1];
    }
    int maxAccuracy = 0;
    int bestTheta = results[0][0];
    for (int i = 0; i < m; i++) {
        int theta = results[i][0];
        int accuracy = predict(theta, results);
        if (accuracy >= maxAccuracy) {
            maxAccuracy = accuracy;
            bestTheta = theta;
        }
    }
    cout << bestTheta << endl;

    return 0;
}
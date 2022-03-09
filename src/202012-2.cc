#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// int predict(long long theta, long long results[][2], int len)
// {
//     int passList1[len], passList2[len];
//     for (int i = 0; i < len; i++) {
//         passList1[i] = results[i][1];
//         passList2[i] = (results[i][0] >= theta) ? 1 : 0;
//     }
//     int sum = 0;
//     for (int i = 0; i < len; i++) {
//         sum += !(passList1[i] ^ passList2[i]);
//     }
//     return sum;
// }

// bool byTheta(pair<int, int> p1, pair<int, int> p2)
// {
//     return p1.first < p2.first;
// }

int main(int argc, char const* argv[])
{
    int m;
    cin >> m;
    vector<pair<int, int>> results;
    for (int i = 0; i < m; i++) {
        int theta, result;
        cin >> theta >> result;
        results.push_back(make_pair(theta, result));
    }
    sort(results.begin(), results.end());
    // compute prefix sum, O(n)
    int preSum[m];
    preSum[0] = results[0].second;
    for (int i = 1; i < m; i++) {
        preSum[i] = preSum[i - 1] + results[i].second;
    }
    int bestTheta = results[0].first;
    int maxPredict = preSum[m - 1];
    for (int i = 1; i < m; i++) {
        if (results[i].first == results[i - 1].first) {
            continue;
        }
        int theta = results[i].first;
        // number of result 0 before theta
        int predict1 = i - preSum[i - 1];
        // number of result 1 after theta
        int predict2 = preSum[m - 1] - preSum[i - 1];
        // the prediction of theta must be true
        int predict = predict1 + predict2;
        if (predict >= maxPredict) {
            bestTheta = theta;
            maxPredict = predict;
        }
    }
    cout << bestTheta << endl;

    // O(n^2), may cause TLE
    // int maxAccuracy = 0;
    // long long bestTheta = results[0][0];
    // for (int i = 0; i < m; i++) {
    //     long long theta = results[i][0];
    //     int accuracy = predict(theta, results, m);
    //     if (accuracy >= maxAccuracy) {
    //         maxAccuracy = accuracy;
    //         bestTheta = theta;
    //     }
    // }
    // cout << bestTheta << endl;

    return 0;
}
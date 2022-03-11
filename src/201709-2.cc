#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool sortByTime(vector<int> op1, vector<int> op2)
{
    // early first
    if (op1[1] != op2[1]) {
        return op1[1] < op2[1];
    }
    // put back first
    else if (op1[2] != op2[2]) {
        return op1[2] < op2[2];
    }
    // small id first
    else {
        return op1[0] < op2[0];
    }
}

int main(int argc, char const* argv[])
{
    int n, k;
    cin >> n >> k;

    int operation[3];
    vector<vector<int>> operations(2 * k, vector<int>(3));
    for (int i = 0; i < k; i++) {
        cin >> operation[0] >> operation[1] >> operation[2];
        // key id
        operations[2 * i][0] = operations[2 * i + 1][0] = operation[0];
        // operation time
        operations[2 * i][1] = operation[1];
        operations[2 * i + 1][1] = operation[1] + operation[2];
        // operation type, 1:withdraw 0:put back
        operations[2 * i][2] = 1;
        operations[2 * i + 1][2] = 0;
    }
    sort(operations.begin(), operations.end(), sortByTime);

    int keys[n];
    for (int i = 0; i < n; i++) {
        keys[i] = i + 1;
    }

    for (int i = 0; i < 2 * k; i++) {
        // handle withdraw
        if (operations[i][2]) {
            for (int j = 0; j < n; j++) {
                if (keys[j] == operations[i][0]) {
                    keys[j] = 0;
                    break;
                }
            }
        }
        // handle put back
        else {
            for (int j = 0; j < n; j++) {
                if (keys[j] == 0) {
                    keys[j] = operations[i][0];
                    break;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << keys[i] << " ";
    }
    cout << endl;

    return 0;
}
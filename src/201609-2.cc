#include <memory.h>

#include <iostream>
#include <vector>

using namespace std;

#define ROW 20
#define SEATS 100

int main(int argc, char const* argv[])
{
    int n, seat;
    cin >> n;
    int seats[SEATS] = { 0 };
    int vacant[ROW] = { 0 };
    for (int i = 0; i < ROW; i++) {
        vacant[i] = 5;
    }
    vector<vector<int>> tickets(n);
    for (int i = 0; i < n; i++) {
        cin >> seat;
        int flag = 0;
        vector<int> ticket;
        for (int j = 0; j < ROW && !flag; j++) {
            if (seat <= vacant[j]) {
                int startSeat = (j + 1) * 5 - vacant[j];
                for (int k = startSeat; k < startSeat + seat; k++) {
                    seats[k] = 1;
                    ticket.push_back(k);
                }
                flag = 1;
                vacant[j] -= seat;
            }
        }
        if (!flag) {
            for (int j = 0; j < SEATS && seat > 0; j++) {
                if (seats[j] == 0) {
                    seats[j] = 1;
                    vacant[j / 5]--;
                    seat--;
                    ticket.push_back(j);
                }
            }
        }
        tickets[i] = ticket;
    }
    for (int i = 0; i < n; i++) {
        for (vector<int>::iterator it = tickets[i].begin(); it != tickets[i].end();
             it++) {
            cout << *it + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}
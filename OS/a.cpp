#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main() {
    int RQ[100], i, j, n, TotalHeadMoment = 0, initial, size, move;
    cout << "Enter the number of Requests: ";
    cin >> n;
    cout << "Enter the Requests sequence: ";
    for (i = 0; i < n; i++)
        cin >> RQ[i];
    cout << "Enter initial head position: ";
    cin >> initial;
    cout << "Enter total disk size: ";
    cin >> size;
    cout << "Enter the head movement direction for high (1) and for low (0): ";
    cin >> move;

    // Logic for C-Scan disk scheduling

    /* Logic to sort the request array */
    sort(RQ, RQ + n);

    int index;
    for (i = 0; i < n; i++) {
        if (initial < RQ[i]) {
            index = i;
            break;
        }
    }

    // If movement is towards high value
    if (move == 1) {
        for (i = index; i < n; i++) {
            TotalHeadMoment += abs(RQ[i] - initial);
            initial = RQ[i];
        }
        // Last movement for max size
        TotalHeadMoment += abs(size - RQ[i - 1] - 1);
        /* Movement from max to min disk */
        TotalHeadMoment += abs(size - 1 - 0);
        initial = 0;
        for (i = 0; i < index; i++) {
            TotalHeadMoment += abs(RQ[i] - initial);
            initial = RQ[i];
        }
    }
    // If movement is towards low value
    else {
        for (i = index - 1; i >= 0; i--) {
            TotalHeadMoment += abs(RQ[i] - initial);
            initial = RQ[i];
        }
        // Last movement for min size
        TotalHeadMoment += abs(RQ[i + 1] - 0);
        /* Movement from min to max disk */
        TotalHeadMoment += abs(size - 1 - 0);
        initial = size - 1;
        for (i = n - 1; i >= index; i--) {
            TotalHeadMoment += abs(RQ[i] - initial);
            initial = RQ[i];
        }
    }

    cout << "Total head movement is " << TotalHeadMoment << endl;
    return 0;
}

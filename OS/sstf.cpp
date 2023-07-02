#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

// Function to calculate the absolute difference between two numbers
int absDiff(int a, int b) {
    return abs(a - b);
}

int main() {
    int n, head;

    cout << "Enter the number of requests: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of requests. Exiting the program." << endl;
        return 0;
    }

    vector<int> arr(n);

    cout << "Enter the request values:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Request " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "Enter the initial head position: ";
    cin >> head;

    int totalSeekTime = 0;
    int current = head;

    cout << "Seek Sequence: ";
    for (int i = 0; i < n; i++) {
        int shortestSeekTime = INT_MAX;
        int shortestSeekTimeIndex = -1;

        for (int j = 0; j < n; j++) {
            int diff = absDiff(arr[j], current);

            if (diff < shortestSeekTime) {
                shortestSeekTime = diff;
                shortestSeekTimeIndex = j;
            }
        }

        cout << arr[shortestSeekTimeIndex] << " ";
        totalSeekTime += shortestSeekTime;
        current = arr[shortestSeekTimeIndex];
        arr[shortestSeekTimeIndex] = INT_MAX;
    }

    cout << endl;
    cout << "Total Seek Time: " << totalSeekTime << endl;
float tpt;
 tpt=(float)n/(float)totalSeekTime;
 cout<<"throughput= "<<tpt;
    return 0;
}

// Enter the number of requests: 7
// Enter the request values:
// Request 1: 24
// Request 2: 57
// Request 3: 89
// Request 4: 26
// Request 5: 11
// Request 6: 95
// Request 7: 59
// Enter the initial head position: 50
// Seek Sequence: 57 59 89 95 26 24 11
// Total Seek Time: 129
// go to right direction firt then 
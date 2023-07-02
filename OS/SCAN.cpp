#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int callSCAN(int arr[], int init, int maxreq, int len) {
    int sum = 0;

    // Sorting the requests
    sort(arr, arr + len);

    // Finding the virtual location of init in the request array
    int pos = lower_bound(arr, arr + len, init) - arr;

    int left = pos - 1;
    int right = pos;

    // Moving towards the right side first in the array
    sum += abs(init - arr[right]);
    cout << arr[right] << endl;

    while (right < len - 1) {
        sum += abs(arr[right] - arr[right + 1]);
        cout << arr[right + 1] << endl;
        right++;
    }

    // Moving to the maximum possible track request from where the head will reverse its direction
    sum += abs(arr[len - 1] - maxreq);
    cout << maxreq << endl;

    // Now moving towards the left direction
    sum += abs(maxreq - arr[left]);
    cout << arr[left] << endl;

    while (left != 0) {
        sum += abs(arr[left] - arr[left - 1]);
        cout << arr[left - 1] << endl;
        left--;
    }

    return sum;
}

int main() {
    int maxreq;
    cout << "Enter the maximum number of cylinders: ";
    cin >> maxreq;

    int len;
    cout << "Enter the number of disk requests: ";
    cin >> len;

    int arr[len];
    cout << "Enter the disk request queue: ";
    for (int i = 0; i < len; ++i) {
        cin >> arr[i];
    }

    int init;
    cout << "Enter the current head position: ";
    cin >> init;

    int res = callSCAN(arr, init, maxreq, len);
    cout << "Total Head Movement: " << res << endl;

float tpt;

 tpt=(float)len/(float)res;
 cout<<"throughput= "<<tpt;
    return 0;
}
// moving in right direction only


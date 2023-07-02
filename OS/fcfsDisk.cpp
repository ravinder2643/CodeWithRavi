#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int headPosition, totalRequests;

    cout << "Enter the current head position: ";
    cin >> headPosition;

    cout << "Enter the total number of disk requests: ";
    cin >> totalRequests;   a

    int* requests = new int[totalRequests];

    cout << "Enter the disk request positions:\n";
    for (int i = 0; i < totalRequests; i++) {
        cout << "Request " << (i + 1) << ": ";
        cin >> requests[i];
    }

    // Calculate the total head movement
    int totalHeadMovement = 0;

    // Process each request in the order of arrival
    for (int i = 0; i < totalRequests; i++) {
        // Calculate the absolute difference between head position and current request
        int headMovement = abs(requests[i] - headPosition);

        // Update the head position
        headPosition = requests[i];

        // Accumulate the head movement
        totalHeadMovement += headMovement;
    }

    cout << "\nTotal head movement: " << totalHeadMovement << endl;\

    // Deallocate the dynamically allocated memory
    delete[] requests;

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

bool compareArrivalTime(const process& p1, const process& p2) {
    return p1.arrival_time < p2.arrival_time;
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<process> processes(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter the arrival time and burst time for process " << i+1 << ": ";
        cin >> processes[i].arrival_time >> processes[i].burst_time;
        processes[i].pid = i+1;
    }

    sort(processes.begin(), processes.end(), compareArrivalTime);

    int current_time = 0;
    int total_waiting_time = 0, total_turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }
        processes[i].waiting_time = current_time - processes[i].arrival_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        current_time += processes[i].burst_time;
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    cout << "\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << processes[i].pid << "\t\t" << processes[i].arrival_time << "\t\t" << processes[i].burst_time << "\t\t" << processes[i].waiting_time << "\t\t" << processes[i].turnaround_time << endl;
    }

    double average_waiting_time = (double) total_waiting_time / n;
    double average_turnaround_time = (double) total_turnaround_time / n;
    cout << "\nAverage waiting time: " << average_waiting_time << endl;
    cout << "Average turnaround time: " << average_turnaround_time << endl;

    return 0;
}

#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

// Defining a process structure
struct Process {
    int pid;
    int at;
    int bt;
    int wt;
    int tt;
    int ct;
};

// Function to compare processes by burst time
struct CompareProcess {
    bool operator()(Process const &p1, Process const &p2) {
        return p1.bt > p2.bt;
    }
};

// Function to calculate SJF scheduling
void sjf(vector<Process> processes) {
    priority_queue<Process, vector<Process>, CompareProcess> readyQueue; // Priority queue to store ready processes
    int cpuTime = 0, n = processes.size(), idleTime = 0, totalTAT = 0, totalWT = 0;

    // Sorting processes by arrival time
    sort(processes.begin(), processes.end(), [](Process &p1, Process &p2) {
        return p1.at < p2.at;
    });

    // Looping through all processes
    for(int i=0; i<n; i++) {
        // Adding processes to the ready queue that have arrived until current CPU time
        while(i < n && processes[i].at <= cpuTime) {
            readyQueue.push(processes[i]);
            i++;
        }

        // Checking if ready queue is empty or not
        if(readyQueue.empty()) {
            // CPU is idle
            idleTime++;
            cpuTime = processes[i].at;
            i--;
        } else {
            // Executing shortest job
            Process currProcess = readyQueue.top();
            readyQueue.pop();

            currProcess.wt = cpuTime - currProcess.at;
            currProcess.ct = cpuTime + currProcess.bt;
            currProcess.tt = currProcess.ct - currProcess.at;
            totalTAT += currProcess.tt;
            totalWT += currProcess.wt;
            cpuTime = currProcess.ct;
        }
    }

    // Calculating average turnaround time and average waiting time
    double avgTAT = (double)totalTAT/n;
    double avgWT = (double)totalWT/n;

    // Printing results
    cout << "Process ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n";
    for(int i=0; i<n; i++) {
        cout << processes[i].pid << "\t\t" << processes[i].at << "\t\t" << processes[i].bt << "\t\t" << processes[i].ct << "\t\t" << processes[i].tt << "\t\t" << processes[i].wt << "\n";
    }
    cout << "\nAverage Turnaround Time: " << avgTAT << "\n";
    cout << "Average Waiting Time: " << avgWT << "\n";
    cout << "CPU Idle Time: " << idleTime << "\n";
}

// Main function to test the SJF scheduling algorithm
int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);
    cout << "Enter the arrival time and burst time for each process:\n";
    for(int i=0; i<n; i++) {
        processes[i].pid = i+1;
        cout << "Process " << i + 1 << ": ";
    cin >> processes[i].at >> processes[i].bt;
}

sjf(processes);

return 0;

}
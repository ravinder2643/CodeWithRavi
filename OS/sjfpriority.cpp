//working
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Process {
    int pid;
    int at;
    int bt;
    int pt;
    int ct;
    int wt;
    int tt;
};

bool comp(Process a, Process b) {
    if (a.at != b.at) {
        return a.at < b.at;
    }
    else if (a.pt != b.pt) {
        return a.pt < b.pt;
    }
    return a.bt < b.bt;
}

void sjf_with_priority(vector<Process>& processes) {
    int n = processes.size();

    sort(processes.begin(), processes.end(), comp);

    int curr_time = 0;
    int total_tat = 0;
    int total_wt = 0;
    int cpu_idle_time = 0;

    for (int i = 0; i < n; i++) {
        if (processes[i].at > curr_time) {
            cpu_idle_time += processes[i].at - curr_time;
            curr_time = processes[i].at;
        }

        int min_bt = processes[i].bt;
        int min_index = i;

        for (int j = i + 1; j < n && processes[j].at <= curr_time; j++) {
            if (processes[j].pt < processes[min_index].pt) {
                min_index = j;
                min_bt = processes[j].bt;
            }
            else if (processes[j].pt == processes[min_index].pt && processes[j].bt < min_bt) {
                min_index = j;
                min_bt = processes[j].bt;
            }
        }

        swap(processes[i], processes[min_index]);

        curr_time += processes[i].bt;
        processes[i].ct = curr_time;
        processes[i].tt = processes[i].ct - processes[i].at;
        processes[i].wt = processes[i].tt - processes[i].bt;

        total_tat += processes[i].tt;
        total_wt += processes[i].wt;
    }

    double avg_tat = (double)total_tat / n;
    double avg_wt = (double)total_wt / n;

    cout << "Process ID\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting Time\n";
    for (int i = 0; i < n; i++) {
        cout << processes[i].pid << "\t\t" << processes[i].at << "\t\t" << processes[i].bt << "\t\t" << processes[i].pt
             << "\t\t" << processes[i].ct << "\t\t" << processes[i].tt << "\t\t" << processes[i].wt << endl;
    }

    cout << "\nAverage Turnaround Time: " << avg_tat << endl;
    cout << "Average Waiting Time: " << avg_wt << endl;
    cout << "CPU Idle Time: " << cpu_idle_time << endl;
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    cout << "Enter the arrival time, burst time, and priority for each process:\n";
    for (int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << ": ";
       
    cin >> processes[i].at >> processes[i].bt >> processes[i].pt;
    processes[i].pid = i + 1;
}

sjf_with_priority(processes);

return 0;
}
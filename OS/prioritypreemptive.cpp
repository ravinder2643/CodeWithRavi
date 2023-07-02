#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int tbt=0;
struct Process {
    int id;
    int arrivalTime;
    int tempBT;
    int burstTime;
    int priority;
    int startTime;
    int completionTime;
    int waitingTime;
    int turnaroundTime;
    bool executed;
    int tempst;
    Process(int id, int arrivalTime, int burstTime, int priority)
        : id(id), arrivalTime(arrivalTime), burstTime(burstTime),
          tempBT(burstTime), priority(priority), startTime(0),
          completionTime(0), waitingTime(0), turnaroundTime(0),
          executed(false)
    {}
};

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    
    vector<Process> processes;

    cout << "Enter Arrival, Burst, Priority: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "For process " << (i + 1) << ":" << endl;

        int arrivalTime, burstTime, priority;
        cin >> arrivalTime >> burstTime >> priority;
          tbt+=burstTime;
        Process process(i + 1, arrivalTime, burstTime, priority);
        processes.push_back(process);
    }

    // Sort processes based on arrival time
    sort(processes.begin(), processes.end(),
         [](const Process& p1, const Process& p2) {
             return p1.arrivalTime < p2.arrivalTime;
         });

    int currentTime = 0;
    int completedProcesses = 0;

    while (completedProcesses < n) {
        int highestPriority = INT_MAX;
        int selectedProcessIndex = -1;

        for (int i = 0; i < n; i++) {
            Process& process = processes[i];

            if (!process.executed && process.arrivalTime <= currentTime && process.priority < highestPriority) {
                highestPriority = process.priority;
                selectedProcessIndex = i;
            }
        }

        if (selectedProcessIndex == -1) {
            currentTime++;
            continue;
        }

        Process& selectedProcess = processes[selectedProcessIndex];
        selectedProcess.executed = true;
        selectedProcess.startTime = currentTime;
        selectedProcess.tempst=selectedProcess.startTime;
        selectedProcess.completionTime = currentTime + 1;

        selectedProcess.turnaroundTime = selectedProcess.completionTime - selectedProcess.arrivalTime;
        selectedProcess.waitingTime = selectedProcess.turnaroundTime - selectedProcess.tempBT;

        currentTime++;

        if (selectedProcess.burstTime > 1) {
            selectedProcess.burstTime--;
            selectedProcess.executed = false;
        } else {
            completedProcesses++;
        }
    }

    float AverageWaitingTime = 0.0, AverageTurnaroundTime = 0.0;
    for (const Process& p : processes) {
        AverageTurnaroundTime += p.turnaroundTime;
        AverageWaitingTime += p.waitingTime;
      
    }

    cout << "\nProcess\t\tArrival\t\tBurst\t\tStart\t\tCompletion\t\tWaiting\t\tTurnaround" << endl;
    cout << "----------------------------------------------------------------------------------------------" << endl;
    for (const Process& process : processes) {
        cout << process.id << "\t\t" << process.arrivalTime << "\t\t" << process.tempBT << "\t\t" <<
            process.tempst << "\t\t" << process.completionTime << "\t\t\t" << process.waitingTime <<
            "\t\t\t" << process.turnaroundTime << endl;
    }

       cout << "Average Waiting time: " << AverageWaitingTime/n << endl;
    cout << "Average Turnaround Time: " << AverageTurnaroundTime/n << endl;
    cout<<"Throughput:"<<(float)n/tbt ;
     

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

class Process {
private:
    int id;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int waitingTime;
    int turnAroundTime;

public:
    Process(int id, int arrivalTime, int burstTime) {
        this->id = id;
        this->arrivalTime = arrivalTime;
        this->burstTime = burstTime;
        this->completionTime = 0;
        this->waitingTime = 0;
        this->turnAroundTime = 0;
    }

    int getId() const {
        return id;
    }

    int getArrivalTime() const {
        return arrivalTime;
    }

    int getBurstTime() const {
        return burstTime;
    }

    int getCompletionTime() const {
        return completionTime;
    }

    void setCompletionTime(int completionTime) {
        this->completionTime = completionTime;
    }

    int getWaitingTime() const {
        return waitingTime;
    }

    void setWaitingTime(int waitingTime) {
        this->waitingTime = waitingTime;
    }

    int getTurnAroundTime() const {
        return turnAroundTime;
    }

    void setTurnAroundTime(int turnAroundTime) {
        this->turnAroundTime = turnAroundTime;
    }
};

class RoundRobinScheduler {
private:
    vector<Process> processes;
    int timeQuantum;

public:
    RoundRobinScheduler(int numProcesses, int timeQuantum) {
        processes.resize(numProcesses);
        this->timeQuantum = timeQuantum;
    }

    void inputProcessDetails() {
        for (int i = 0; i < processes.size(); i++) {
            cout << "Enter the arrival time and burst time for Process " << (i + 1) << ":\n";
            int arrivalTime, burstTime;
            cin >> arrivalTime >> burstTime;
            processes[i] = Process(i + 1, arrivalTime, burstTime);
        }
    }

    void runScheduler() {
        vector<int> remainingTime(processes.size(), 0);
        int currentTime = 0;
        bool allProcessesCompleted = false;

        for (int i = 0; i < processes.size(); i++) {
            remainingTime[i] = processes[i].getBurstTime();
        }

        while (!allProcessesCompleted) {
            allProcessesCompleted = true;

            for (Process& process : processes) {
                int index = process.getId() - 1;

                if (remainingTime[index] > 0) {
                    allProcessesCompleted = false;

                    if (remainingTime[index] <= timeQuantum) {
                        currentTime += remainingTime[index];
                        remainingTime[index] = 0;
                        process.setCompletionTime(currentTime);
                    } else {
                        currentTime += timeQuantum;
                        remainingTime[index] -= timeQuantum;
                    }
                }
            }
        }
    }

    void calculateTimes() {
        for (Process& process : processes) {
            int waitingTime = process.getCompletionTime() - process.getArrivalTime() - process.getBurstTime();
            process.setWaitingTime(waitingTime);

            int turnAroundTime = process.getCompletionTime() - process.getArrivalTime();
            process.setTurnAroundTime(turnAroundTime);
        }
    }

    void printProcessDetails() {
        cout << "\nProcess\tArrival Time\tBurst Time\tCompletion Time\t\tWaiting Time\tTurnaround Time\n";
        for (const Process& process : processes) {
                        cout << process.getId() << "\t\t" << process.getArrivalTime() << "\t\t" << process.getBurstTime()
                << "\t\t" << process.getCompletionTime() << "\t\t\t" << process.getWaitingTime()
                << "\t\t" << process.getTurnAroundTime() << endl;
        }
    }

    void printAverageTimes() {
        int totalWaitingTime = 0;
        int totalTurnAroundTime = 0;

        for (const Process& process : processes) {
            totalWaitingTime += process.getWaitingTime();
            totalTurnAroundTime += process.getTurnAroundTime();
        }

        double averageWaitingTime = static_cast<double>(totalWaitingTime) / processes.size();
        double averageTurnAroundTime = static_cast<double>(totalTurnAroundTime) / processes.size();

        cout << "\nAverage Waiting Time: " << averageWaitingTime << endl;
        cout << "Average Turnaround Time: " << averageTurnAroundTime << endl;
    }
};

int main() {
    int numProcesses, timeQuantum;

    cout << "Enter the total number of processes: ";
    cin >> numProcesses;

    cout << "Enter the time quantum: ";
    cin >> timeQuantum;

    RoundRobinScheduler scheduler(numProcesses, timeQuantum);
    scheduler.inputProcessDetails();
    scheduler.runScheduler();
    scheduler.calculateTimes();
    scheduler.printProcessDetails();
    scheduler.printAverageTimes();

    return 0;
}


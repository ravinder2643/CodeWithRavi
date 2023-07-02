#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Process {
public:
    string name;
    int arrivalTime;
    int burstTime;
    int age = 3;

    Process(string name, int arrivalTime, int burstTime) {
        this->name = name;
        this->arrivalTime = arrivalTime;
        this->burstTime = burstTime;
    }
};

//sort based on arrival time
bool arrivalComparator(const Process& p1, const Process& p2) {
    return p1.arrivalTime < p2.arrivalTime;
}

//sort based on burst time
bool burstComparator(const Process& p1, const Process& p2) {
    return p1.burstTime < p2.burstTime;
}

void calculate(string name, int at, int bt, int& currentTime) {
    int st = currentTime;
    int ct = st + bt;
    currentTime += bt;

    int tat = ct - at;
    int wt = tat - bt;

    cout << name << "\t\t" << at << "\t\t" << bt << "\t\t" << st << "\t\t\t" << ct << "\t\t\t" << tat << "\t\t\t" << wt << endl;
}

int main() {
    vector<Process> processes;
    vector<Process> temp;

    int currentTime = 0;

    cout << "Enter the number of processes: ";
    int n;
    cin >> n;

    cout << "Enter process Arrival & Burst time :" << endl;
    for (int i = 0; i < n; i++) {
        cout << "For Process " << i << ":" << endl;
        int arrivalTime, burstTime;
        cin >> arrivalTime >> burstTime;

        processes.emplace_back("P" + to_string(i), arrivalTime, burstTime);
    }

    //sort based on arrival time
    sort(processes.begin(), processes.end(), arrivalComparator);

    cout << "PID\t\t" << "Arrival\t\t" << "Burst\t\t" << "Starting\t\t" << "Completion\t\t" << "TurnAround\t\t" << "Waiting" << endl;

    //calculate 1st process
    calculate(processes[0].name, processes[0].arrivalTime, processes[0].burstTime, currentTime);

    processes.erase(processes.begin());

    while (!processes.empty() || !temp.empty()) {
        //add process which has arrived into temporary list
        if (!processes.empty()) {
            for (auto it = processes.begin(); it != processes.end(); ) {
                if (it->arrivalTime <= currentTime) {
                    temp.push_back(*it);
                    it = processes.erase(it);
                } else {
                    ++it;
                }
            }
        }

        //sort based on burst time
        sort(temp.begin(), temp.end(), burstComparator);

        bool flag = false;
        for (auto it = temp.begin(); it != temp.end(); ) {
            if (it->age == 0) {
                flag = true;
                calculate(it->name, it->arrivalTime, it->burstTime, currentTime);
                it = temp.erase(it);
            } else {
                it->age -= 1;
                ++it;
            }
        }

        if (!flag && !temp.empty()) {
            calculate(temp[0].name, temp[0].arrivalTime, temp[0].burstTime, currentTime);
            for (auto& p : temp) {
                p.age -= 1;
            }
            temp.erase(temp.begin());
        }
    }

    return 0;
}
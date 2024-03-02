#include <iostream>
using namespace std;

struct Process {
    int pid;
    int bt;
    int wt, tt;
};

int main() {
    int n, totwt = 0, tottt = 0;
    float avg1, avg2;
    int total_time = 0;

    cout << "Enter the number of processes: ";
    cin >> n;

    Process p[10];

    for(int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        cout << "Enter the burst time for process " << p[i].pid << ": ";
        cin >> p[i].bt;
        total_time += p[i].bt;
    }

    p[0].wt = 0;
    p[0].tt = p[0].bt + p[0].wt;

    for(int i = 1; i < n; i++) {
        p[i].wt = p[i - 1].bt + p[i - 1].wt;
        p[i].tt = p[i].bt + p[i].wt;
    }

    cout << "\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n";

    for(int i = 0; i < n; i++) {
        cout << p[i].pid << "\t\t" << p[i].bt << "\t\t" << p[i].wt << "\t\t" << p[i].tt << endl;
        totwt += p[i].wt;
        tottt += p[i].tt;
    }

    avg1 = (float)totwt / n;
    avg2 = (float)tottt / n;
    
    cout << "\nAverage Waiting Time: " << avg1 << endl;
    cout << "Average Turnaround Time: " << avg2 << endl;
    
    // Printing Gantt Chart
    cout << "\nGantt Chart:" << endl;
    for (int i = 0; i < total_time; i++) {
        cout << "-";
    }
    cout << "\n|";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p[i].bt; j++) {
            cout << "P" << p[i].pid;
        }
        cout << "|";
    }
    cout << endl;

    return 0;
}

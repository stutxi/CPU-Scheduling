#include <iostream>
using namespace std;

struct Process {
    int pid;
    int bt;
    int wt;
    int tt;
} p[10], temp;

int main() {
    int n, totwt = 0, tottt = 0;
    float avg1, avg2;
    int total_time = 0;

    cout << "Enter the number of processes: ";
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cout << "Enter the burst time for process " << i << ": ";
        cin >> p[i].bt;
        p[i].pid = i;
        total_time += p[i].bt;
    }

    // Sorting processes based on burst time using selection sort
    for(int i = 1; i < n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(p[i].bt > p[j].bt) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    p[1].wt = 0;
    p[1].tt = p[1].bt + p[1].wt;

    for(int i = 2; i <= n; i++) {
        p[i].wt = p[i - 1].bt + p[i - 1].wt;
        p[i].tt = p[i].bt + p[i].wt;
    }

    cout << "\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n";

    for(int i = 1; i <= n; i++) {
        cout << p[i].pid << "\t\t" << p[i].bt << "\t\t" << p[i].wt << "\t\t" << p[i].tt << endl;
        totwt += p[i].wt;
        tottt += p[i].tt;
    }

    avg1 = (float) totwt / n;
    avg2 = (float) tottt / n;

    cout << "\nAverage Waiting Time: " << avg1 << endl;
    cout << "Average Turnaround Time: " << avg2 << endl;

    // Printing Gantt Chart
    cout << "\nGantt Chart:\n";
    cout << "------------------------------\n";
    cout << "|";

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < p[i].bt; j++) {
            cout << "P" << p[i].pid;
        }
        cout << "|";
    }

    return 0;
}

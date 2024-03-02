#include <iostream>
using namespace std;

int main() {
    int n, t, max;
    float awt = 0, att = 0, temp = 0;

    cout << "Enter the number of processes: ";
    cin >> n;

    int bu[n], wa[n], tat[n], ct[n];

    // Input burst times for each process
    for (int i = 0; i < n; i++) {
        cout << "Enter the burst time for process " << i + 1 << ": ";
        cin >> bu[i];
        ct[i] = bu[i]; // Store burst time in ct array
    }

    cout << "\nEnter the size of time slice: ";
    cin >> t;

    // Find maximum burst time
    max = bu[0];
    for (int i = 1; i < n; i++)
        if (max < bu[i])
            max = bu[i];

    // Perform scheduling using round robin with given time slice
    for (int j = 0; j < (max / t) + 1; j++)
        for (int i = 0; i < n; i++)
            if (bu[i] != 0)
                if (bu[i] <= t) {
                    tat[i] = temp + bu[i]; // Calculate turnaround time
                    temp = temp + bu[i];
                    bu[i] = 0;
                } else {
                    bu[i] = bu[i] - t;
                    temp = temp + t;
                }

    // Calculate waiting time and turnaround time
    for (int i = 0; i < n; i++) {
        wa[i] = tat[i] - ct[i];
        att += tat[i];
        awt += wa[i];
    }

    // Output average turnaround time and average waiting time as floats
    cout << "\nAverage Waiting Time: " << awt / (float)n << endl;
    cout << "Average Turnaround Time: " << att / (float)n << endl;

    // Output Gantt Chart
    cout << "\nGantt Chart:\n------------------------------\n|";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bu[i]; j++) {
            cout << "P" << i + 1;
        }
        cout << "|";
    }
    cout << endl;

    // Output process details
    cout << "\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++)
        cout << i + 1 << "\t\t" << ct[i] << "\t\t" << wa[i] << "\t\t" << tat[i] << endl;

    return 0;
}

#include <stdio.h>

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
};

void fcfs(struct Process processes[], int n) {
    int current_time = 0;

    for (int i = 0; i < n; i++) {
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }

        processes[i].completion_time = current_time + processes[i].burst_time;
        current_time = processes[i].completion_time;

        printf("Process %d: Arrival Time: %d, Burst Time: %d, Completion Time: %d\n",
               processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].completion_time);
    }
}

int main() {
    struct Process processes[] = {
        {1, 0, 5, 0},
        {2, 1, 3, 0},
        {3, 2, 8, 0},
        {4, 3, 6, 0}
    };

    int n = sizeof(processes) / sizeof(processes[0]);

    printf("FCFS Scheduling Algorithm\n");
    fcfs(processes, n);

    return 0;
}

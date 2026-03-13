#include <stdio.h>

struct Process {
    int pid, at, bt, ct, tat, wt, rt, rem_bt, start;
};

int main() {
    int n, choice, time = 0, completed = 0;
    float avg_tat = 0, avg_wt = 0, avg_rt = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];
    for(int i=0; i<n; i++) {
        p[i].pid = i+1;
        printf("Enter AT and BT for P%d: ", i+1);
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].rem_bt = p[i].bt;
    }

    printf("\nChoose Scheduling:\n1. Non-preemptive SJF\n2. Preemptive SJF\n");
    scanf("%d", &choice);

    printf("\nGantt Chart:\n");

    switch(choice) {
        case 1: // Non-preemptive SJF
            while(completed < n) {
                int idx = -1;
                for(int i=0; i<n; i++) {
                    if(p[i].at <= time && p[i].rem_bt > 0) {
                        if(idx == -1 || p[i].bt < p[idx].bt)
                            idx = i;
                    }
                }
                if(idx == -1) { time++; continue; }

                // Print Gantt chart block
                printf("| P%d (%d-%d) ", p[idx].pid, time, time + p[idx].bt);

                p[idx].start = time;
                time += p[idx].bt;
                p[idx].ct = time;
                p[idx].tat = p[idx].ct - p[idx].at;
                p[idx].wt = p[idx].tat - p[idx].bt;
                p[idx].rt = p[idx].start - p[idx].at;
                p[idx].rem_bt = 0;
                completed++;
            }
            break;

        case 2: // Preemptive SJF (SRTF)
            while(completed < n) {
                int idx = -1;
                for(int i=0; i<n; i++) {
                    if(p[i].at <= time && p[i].rem_bt > 0) {
                        if(idx == -1 || p[i].rem_bt < p[idx].rem_bt)
                            idx = i;
                    }
                }
                if(idx == -1) { time++; continue; }

                // Print Gantt chart block (unit by unit)
                printf("| P%d (%d-%d) ", p[idx].pid, time, time+1);

                if(p[idx].rem_bt == p[idx].bt) p[idx].start = time;
                p[idx].rem_bt--; time++;

                if(p[idx].rem_bt == 0) {
                    p[idx].ct = time;
                    p[idx].tat = p[idx].ct - p[idx].at;
                    p[idx].wt = p[idx].tat - p[idx].bt;
                    p[idx].rt = p[idx].start - p[idx].at;
                    completed++;
                }
            }
            break;
    }
    printf("|\n");

    // Table of results
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for(int i=0; i<n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt,
               p[i].ct, p[i].tat, p[i].wt, p[i].rt);
        avg_tat += p[i].tat;
        avg_wt += p[i].wt;
        avg_rt += p[i].rt;
    }

    printf("\nAverage TAT = %.2f", avg_tat/n);
    printf("\nAverage WT  = %.2f", avg_wt/n);
    printf("\nAverage RT  = %.2f\n", avg_rt/n);

    return 0;
}

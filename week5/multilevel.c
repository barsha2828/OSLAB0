#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Process {
    char name[10];
    int arrival_time;

    int burst_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
    int start_time;
};

void fcfs(struct Process p[], int n, int *time, char gantt[][10], int start[], int finish[], int *gantt_index) {
    for (int i = 0; i < n; i++) {
        if (*time < p[i].arrival_time) {
            *time = p[i].arrival_time; // CPU idle until process arrives
        }
        p[i].start_time = *time;
        p[i].completion_time = *time + p[i].burst_time;
        p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
        p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;

        // Add to Gantt chart
        strcpy(gantt[*gantt_index], p[i].name);
        start[*gantt_index] = p[i].start_time;
        finish[*gantt_index] = p[i].completion_time;
        (*gantt_index)++;

        *time += p[i].burst_time;
    }
}

int main() {
    int n_sys, n_user;
    printf("Enter number of system processes: ");
    scanf("%d", &n_sys);
    struct Process sys[n_sys];

    for (int i = 0; i < n_sys; i++) {
        printf("Enter name, arrival time, burst time for system process %d: ", i+1);
        scanf("%s %d %d", sys[i].name, &sys[i].arrival_time, &sys[i].burst_time);
    }

    printf("Enter number of user processes: ");
    scanf("%d", &n_user);
    struct Process user[n_user];

    for (int i = 0; i < n_user; i++) {
        printf("Enter name, arrival time, burst time for user process %d: ", i+1);
        scanf("%s %d %d", user[i].name, &user[i].arrival_time, &user[i].burst_time);
    }

    char gantt[50][10]; // store process names
    int start[50], finish[50];
    int gantt_index = 0;
    int time = 0;

    // First schedule system processes
    fcfs(sys, n_sys, &time, gantt, start, finish, &gantt_index);

    // Then schedule user processes
    fcfs(user, n_user, &time, gantt, start, finish, &gantt_index);

    // Print results in table format
    printf("\nSystem Processes:\n");
    printf("Name\tAT\tBT\tST\tCT\tTAT\tWT\n");
    for (int i = 0; i < n_sys; i++) {
        printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\n", sys[i].name, sys[i].arrival_time,
               sys[i].burst_time, sys[i].start_time, sys[i].completion_time,
               sys[i].turnaround_time, sys[i].waiting_time);
    }

    printf("\nUser Processes:\n");
    printf("Name\tAT\tBT\tST\tCT\tTAT\tWT\n");
    for (int i = 0; i < n_user; i++) {
        printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\n", user[i].name, user[i].arrival_time,
               user[i].burst_time, user[i].start_time, user[i].completion_time,
               user[i].turnaround_time, user[i].waiting_time);
    }
        // Calculate average waiting time for system processes
    int total_wait_sys = 0;
    for (int i = 0; i < n_sys; i++) {
        total_wait_sys += sys[i].waiting_time;
    }
    float avg_wait_sys = (float)total_wait_sys / n_sys;

    // Calculate average waiting time for user processes
    int total_wait_user = 0;
    for (int i = 0; i < n_user; i++) {
        total_wait_user += user[i].waiting_time;
    }
    float avg_wait_user = (float)total_wait_user / n_user;

    // Calculate overall average waiting time
    int total_wait_all = total_wait_sys + total_wait_user;
    int total_processes = n_sys + n_user;
    float avg_wait_all = (float)total_wait_all / total_processes;

    printf("\nAverage Waiting Time (System Processes): %.2f\n", avg_wait_sys);
    printf("Average Waiting Time (User Processes): %.2f\n", avg_wait_user);
    printf("Overall Average Waiting Time: %.2f\n", avg_wait_all);

    // Print horizontal Gantt chart
    printf("\nGantt Chart:\n");
    for (int i = 0; i < gantt_index; i++) {
        printf("|  %s  ", gantt[i]);
    }
    printf("|\n");

    printf("%d", start[0]);
    for (int i = 0; i < gantt_index; i++) {
        printf("      %d", finish[i]);
    }
    printf("\n");

    return 0;
}

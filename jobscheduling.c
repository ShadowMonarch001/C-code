#include <stdio.h>

void jobScheduling(char jobArray[], int deadlineArray[], int profitArray[], int n) {
    char scheduleArray[n];
    int slotArray[100]; // Assuming maximum deadline is 100
    int i, j, k, maxDeadline = 0;

    // Find the maximum deadline
    for (i = 0; i < n; i++) {
        if (deadlineArray[i] > maxDeadline)
            maxDeadline = deadlineArray[i];
    }

    // Initialize slotArray with all slots available
    for (i = 0; i <= maxDeadline; i++) {
        slotArray[i] = 0;
    }

    // Sort the jobs based on profit in descending order using bubble sort
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-1-i; j++) {
            if (profitArray[j] < profitArray[j+1]) {
                int temp = profitArray[j];
                profitArray[j] = profitArray[j+1];
                profitArray[j+1] = temp;

                temp = deadlineArray[j];
                deadlineArray[j] = deadlineArray[j+1];
                deadlineArray[j+1] = temp;

                char tempJob = jobArray[j];
                jobArray[j] = jobArray[j+1];
                jobArray[j+1] = tempJob;
            }
        }
    }

    // Schedule the jobs
    for (i = 0; i < n; i++) {
        for (j = deadlineArray[i]; j > 0; j--) {
            if (slotArray[j] == 0) {
                slotArray[j] = 1;
                scheduleArray[j] = jobArray[i];
                break;
            }
        }
    }

    // Print the scheduled jobs
    printf("Scheduled jobs: ");
    for (i = 1; i <= maxDeadline; i++) {
        if (slotArray[i] == 1) {
            printf("%c ", scheduleArray[i]);
        }
    }
}

int main() {
    char jobArray[] = {'A', 'B', 'C', 'D', 'E'};
    int deadlineArray[] = {2, 1, 2, 1, 3};
    int profitArray[] = {100, 19, 27, 25, 15};
    int n = sizeof(jobArray) / sizeof(jobArray[0]);

    jobScheduling(jobArray, deadlineArray, profitArray, n);

    return 0;
}


#include <stdio.h>
#include <stdlib.h>

#define MAX_POINTS 100

struct point {
    int x;
    int y;
};

int main() {
    int arr[MAX_POINTS] = {1, 5, 7, 10, 12, 15, 20, 22};
    int n = 8;  // number of elements in the array
    struct point points[MAX_POINTS];
    int num_points = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int valid = 1;
            for (int k = i+1; k < j; k++) {
                if (arr[k] > arr[i] && arr[k] < arr[j]) {
                    valid = 0;
                    break;
                }
            }
            if (valid) {
                points[num_points].x = arr[i];
                points[num_points].y = arr[j];
                num_points++;
            }
        }
    }

    printf("Points with no values between them:\n");
    for (int i = 0; i < num_points; i++) {
        printf("(%d, %d)\n", points[i].x, points[i].y);
    }

    printf("\nDistances between points:\n");
    for (int i = 0; i < num_points; i++) {
        int dist = points[i].y - points[i].x;
        printf("(%d, %d) distance: %d\n", points[i].x, points[i].y, dist);
    }

    return 0;
}

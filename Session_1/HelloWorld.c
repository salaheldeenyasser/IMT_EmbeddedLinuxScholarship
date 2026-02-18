#include <stdio.h>



int sensor_data[10]= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};


float calc_average(int arr[], int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

void copy_window(int arr[], int start, int dist[]) {
    for (int i = 0; i < 3; i++) {
        if(start == 0) {
            dist[0] = 0;
        } else if (start == 10) {
            dist[2] = 0;
        } else {
            dist[0] = arr[start - 1];
            dist[1] = arr[start];
            dist[2] = arr[start + 1];
        }
    }
}
void main() {
    float avarage_data[10];


    for (int i =0; i < 10; i++) {
        int window[3];
        copy_window(sensor_data, i, window);
        avarage_data[i] = calc_average(window, 3);
    }

    for (int i = 0; i < 10; i++) {
        printf("%.2f ", avarage_data[i]);
    }

}

//int moving_window_average(int *data, int size) {
//    int dataWithBoundary[14];
//    int sum = 0;
//    for (int i = 3; i < 13; i++) {
//        dataWithBoundary[i] = data[i-3];
//    }
//    
//    for (int i = 0; i < size; i++) {
//        for (int j = 0; j < 3; j++) {
//            if (i < 3) {
//              sum += dataWithBoundary[i+j];
//            }
//        }
//    }
//    
//    return sum / 3;
//}
/////////////////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT (v4)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement posted on edX:
// (Course > Assignments > Assignment Information & Policies > Academic Integrity Policy)
/////////////////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with: none

// 
//
// Name: Krish Khasnobish
// login ID: kkhasnob
//////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "arr-tools.h"
#include "cs136-trace.h"


// See arr-tools.h for documentation.
int minmax_dist(int arr[], int len) {
    assert(len > 0);
    int i = 0;
    int i_min = 0;
    int i_max = 0;
    int min = arr[0];
    int max = arr[0];
    while (i < len) {
        if (min <= arr[i]) {
            i++;
        } else {
            min = arr[i];
            i_min = i;
            i++;
        }
    }
    int n = 0;
    while (n < len) {
        if (max < arr[n]) {
            max = arr[n];
            i_max = n;
            n++;
        } else {;
            n++;
        }
    }
    return abs(i_max - i_min);
}

// See arr-tools.h for documentation.
int most_occurrences(int arr[], int len) {
    assert(len > 0);
    int freq = arr[0];
    int count_freq = 0;
    int count_curr = 0;
    for (int i = 0; i < len; i++) {
        int n = 0;
        for (; n < len; n++) {
            if (arr[n] == arr[i]) {
                count_curr++;
            }
        }
        if (count_curr > count_freq) {
            freq = arr[i];
            count_freq = count_curr;
            count_curr = 0;
        } else {
            count_curr = 0;
        }
    }
    return freq;
}

// See arr-tools.h for documentation.
// example: arr [2, 4, 4, 2, 6, 2, 3, 5], wnd_size 2
//               ^                       ->   (2)/1 = 2
//               ^  ^                    -> (2+4)/2 = 3
//                  ^  ^                 -> (4+4)/2 = 4
//                     ^  ^              -> (4+2)/2 = 3
//                        ^  ^           -> (2+6)/2 = 4
//                           ^ ^         -> (6+2)/2 = 4
//                              ^  ^     -> (2+3)/2 = 2(.500)
//                                 ^  ^  -> (3+4)/2 = 4
// example: arr [2, 4, 4, 2, 6, 2, 3, 5], wnd_size 4
//               ^                       ->       (2)/1 = 2
//               ^  ^                    ->     (2+4)/2 = 3
//               ^  ^  ^                 ->   (2+4+4)/3 = 3(.333)
//               ^  ^  ^  ^              -> (2+4+4+2)/4 = 3
//                  ^  ^  ^  ^           -> (4+4+2+6)/4 = 4
//                     ^  ^  ^ ^         -> (4+2+6+2)/4 = 3(.500)
//                        ^  ^  ^  ^     -> (2+6+2+3)/4 = 3(.250)
//                           ^  ^  ^  ^  -> (6+2+3+5)/4 = 4
void moving_average(int arr[], int len, int wnd_size) {
    assert(len > 0);
    assert(len <=100);
    assert(wnd_size > 0);
    int i = len - 1;
    while (i >= 0) {
        if (i >= wnd_size) {
            int sum = 0;
            int n = i;
            int count = wnd_size;
            while (count > 0) {
                sum += arr[n];
                n--;
                count--;
            }
            arr[i] = sum / wnd_size;
        } else {
            int sum2 = 0;
            int m = i;
            int count2 = 0;
            while (m >= 0) {
                sum2 += arr[m];
                m--;
                count2++;
            }
            arr[i] = sum2 / count2;
        }
        i--;
    }
}

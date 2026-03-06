#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int value;
    char* keys;
} Chart;

void sort(Chart* chart, int count) {
    int i=1;
    for (;i<count;i++) {
        char* key = chart[i].keys;
        int val = chart[i].value;
        int left = 0, right = i-1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (strcmp(chart[mid].keys, key) > 0) right = mid - 1;
            else left = mid + 1;
        }
        int j = i-1;
        for (;j>left-1;j--) {
            chart[j+1].keys = chart[j].keys;
            chart[j+1].value = chart[j].value;
        }
        chart[left].keys = key;
        chart[left].value = val;
    }
}


int main() {
    int c = 0, count;
    scanf("%d", &count);
    Chart* chart = malloc(count*sizeof(Chart));
    if (!chart) {printf("Error allocating memory\n"); return 0;}
    while (c<count) {chart[c].keys = malloc(101*sizeof(char)); c++; if (!chart[c-1].keys) {printf("Error allocating memory char\n"); free(chart); return 0;}}
    int i=0;
    for (;i<count;i++) {
        scanf("%100s", chart[i].keys);
        scanf("%d", &chart[i].value);
    }
    int number = 0;
    while (number<count) {
        printf("Key: %s, value: %d\n", chart[number].keys, chart[number].value);
        number++;
    }
    sort(chart, count);
    printf("\n========== SORTED ==========\n\n");
    number = 0;
    while (number<count) {
        printf("Key: %s, value: %d\n", chart[number].keys, chart[number].value);
        number++;
    }
    c = 0;
    while (c<count) {
        free(chart[c].keys);
        c++;
    }
    free(chart);
    return 0;
}
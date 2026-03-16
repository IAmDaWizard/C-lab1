#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int value;
    char *keys;
} Chart;

void sort(Chart *chart, int count) {
    int i = 1;
    for (; i < count; i++) {
        char *key = chart[i].keys;
        int val = chart[i].value;
        int left = 0, right = i - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (strcmp(chart[mid].keys, key) > 0) right = mid - 1;
            else left = mid + 1;
        }
        int j = i - 1;
        for (; j > left - 1; j--) {
            chart[j + 1].keys = chart[j].keys;
            chart[j + 1].value = chart[j].value;
        }
        chart[left].keys = key;
        chart[left].value = val;
    }
}


int main() {
    int c = 0, count, ch;
    fprintf(stderr, "Введите количество пар ключ-значение: ");
    scanf("%d", &count);
    while ((ch = getchar()) != '\n' && ch != EOF);
    Chart *chart = malloc(count * sizeof(Chart));
    if (!chart) {
        printf("Error allocating memory\n");
        return 0;
    }
    while (c < count) {
        size_t size = 0;
        chart[c].keys = NULL;
        fprintf(stderr, "Введите ключ: ");
        ssize_t len = getline(&chart[c].keys, &size, stdin);
        if (len==-1) {
            printf("Error allocating memory char\n");
            int i=0; for (;i<c;i++){free(chart[i].keys);}
            free(chart);
            return 0;
        }
        if (len>0 && chart[c].keys[len-1] == '\n') chart[c].keys[len-1] = '\0';
        fprintf(stderr, "Введите значение: ");
        scanf("%d", &chart[c].value);
        while ((ch = getchar()) != '\n' && ch != EOF);
        c++;
    }
    int number = 0;
    while (number < count) {
        printf("Key: %s, value: %d\n", chart[number].keys, chart[number].value);
        number++;
    }
    sort(chart, count);
    printf("\n========== SORTED ==========\n\n");
    number = 0;
    while (number < count) {
        printf("Key: %s, value: %d\n", chart[number].keys, chart[number].value);
        number++;
    }
    c = 0;
    while (c < count) {
        free(chart[c].keys);
        c++;
    }
    free(chart);
    return 0;
}

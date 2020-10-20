#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define num_size 100
#define from "--from="
#define to "--to="

void sort(int *arr, int elemc);

int main(int argc, char **argv) {
    int from_value;
    int to_value;
    int input[num_size];
    int input_check[num_size];
    int from_num = 0;
    int to_num = 0;
    int input_num = 0;
    int change_num = 0;
    if (argc < 2) {
        return -1;
    } else if (argc > 3) {
        return -2;
    }
    for (int i = 0; i < argc; i++) {
        if (strncmp(argv[i], from, strlen(from)) == 0) {
            from_value = strtoll(argv[i] + strlen(from), NULL, 10);
            from_num += 1;
        } else if (strncmp(argv[i], to, strlen(to)) == 0) {
            to_value = strtoll(argv[i] + strlen(to), NULL, 10);
            to_num += 1;
        }
    }
    if (from_num > 1 || to_num > 1) {
        return -3;
    } else if (from_num == 0 && to_num == 0) {
        return -4;
    }
    for (int k = 0; k < num_size; k++) {
        int input_value;
        char space;
        if (scanf("%d%c", &input_value, &space) != 2) {
            break;
        }
        int usecheck = 0;
        if (from_num == 1 && input_value <= from_value) {
            fprintf(stdout, "%d ", input_value);
            usecheck++;
        }
        if (to_num == 1 && input_value >= to_value) {
            fprintf(stderr, "%d ", input_value);
            usecheck++;
        }
        if (!usecheck) {
            input[input_num] = input_value;
            input_check[input_num] = input_value;
            input_num++;
        }
        if (space != ' ') {
            break;
        }
    }
    sort(input, input_num);
    for (int i = 0; i < input_num; i++) {
        if (input[i] != input_check[i]) {
            change_num++;
        }
    }
    return change_num;
}
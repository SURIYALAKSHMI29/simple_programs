/*
Alice and Bob each created one problem for HackerRank. A reviewer rates the two challenges, awarding points on a scale from 1 to 100 for three categories: problem clarity, originality, and difficulty.

The rating for Alice's challenge is the triplet a = (a[0], a[1], a[2]), and the rating for Bob's challenge is the triplet b = (b[0], b[1], b[2]).
The task is to find their comparison points by comparing a[0] with b[0], a[1] with b[1], and a[2] with b[2].
If a[i] > b[i], then Alice is awarded 1 point.
If a[i] < b[i], then Bob is awarded 1 point.
If a[i] = b[i], then neither person receives a point.
Comparison points is the total points a person earned.
Given a and b, determine their respective comparison points.
*/

#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);
int parse_int(char*);

int* compareTriplets(int a_count, int* a, int b_count, int* b, int* result_count) {
    int alice=0,bob=0,i;
    for(i=0;i<a_count;i++){
        if(a[i]>b[i])
            alice++;
        else if(b[i]>a[i])
            bob++;
    }
    int* result = malloc(2 * sizeof(int));
    
    result[0] = alice;
    result[1] = bob;

    *result_count = 2;
    return result;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");
    char** a_temp = split_string(rtrim(readline()));
    int* a = malloc(3 * sizeof(int));
    for (int i = 0; i < 3; i++) {
        int a_item = parse_int(*(a_temp + i));
        *(a + i) = a_item;
    }
    char** b_temp = split_string(rtrim(readline()));
    int* b = malloc(3 * sizeof(int));
    for (int i = 0; i < 3; i++) {
        int b_item = parse_int(*(b_temp + i));
        *(b + i) = b_item;
    }
    int result_count;
    int* result = compareTriplets(3, a, 3, b, &result_count);
    for (int i = 0; i < result_count; i++) {
        fprintf(fptr, "%d", *(result + i));

        if (i != result_count - 1) {
            fprintf(fptr, " ");
        }
    }
    fprintf(fptr, "\n");
    fclose(fptr);
    return 0;
}
char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);
    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);
        if (!line) {
            break;
        }
        data_length += strlen(cursor);
        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }
        alloc_length <<= 1;
        data = realloc(data, alloc_length);
        if (!data) {
            data = '\0';
            break;
        }
    }
    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
        data = realloc(data, data_length);
        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);
        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }
    return data;
}
char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }
    if (!*str) {
        return str;
    }
    while (*str != '\0' && isspace(*str)) {
        str++;
    }
    return str;
}
char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }
    if (!*str) {
        return str;
    }
    char* end = str + strlen(str) - 1;
    while (end >= str && isspace(*end)) {
        end--;
    }
    *(end + 1) = '\0';
    return str;
}
char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");
    int spaces = 0;
    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) {
            return splits;
        }
        splits[spaces - 1] = token;
        token = strtok(NULL, " ");
    }
    return splits;
}
int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);
    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }
    return value;
}

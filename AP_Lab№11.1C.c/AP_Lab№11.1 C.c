#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <stdbool.h>

int count_substring_in_line(const char* line, const char* substring) {
    int count = 0;
    const char* temp = line;
    while ((temp = strstr(temp, substring)) != NULL) {
        count++;
        temp += strlen(substring);
    }
    return count;
}

int count_substring_occurrences(const char* filename, const char* substring) {
    FILE* file = NULL;
    errno_t err = fopen_s(&file, filename, "r");
    if (err != 0 || file == NULL) {
        return -1;
    }

    char line[1000];
    int total_count = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        total_count += count_substring_in_line(line, substring);
    }
    fclose(file);
    return total_count;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const char* filename = "t.txt";
    int occurrences = count_substring_occurrences(filename, "while");

    if (occurrences == -1) {
        printf("Помилка відкриття файлу\n");
        return 1;
    }

    printf("Кількість входжень while: %d\n", occurrences);
    return 0;
}
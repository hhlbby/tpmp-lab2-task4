#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "buildings.h"
void create_initial_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Ошибка при создании файла");
        return;
    }
    fprintf(file, "ул. Ленина, 1|Жилой|5|60|30\n");
    fprintf(file, "пр. Мира, 15|Офисный|12|240|55\n");
    fprintf(file, "ул. Гагарина, 8|Жилой|9|108|70\n");
    fprintf(file, "б-р. Строителей, 3|Торговый|3|15|20\n");
    fprintf(file, "ул. Победы, 22|Административный|7|56|60\n");
    fprintf(file, "пр. Космонавтов, 5|Жилой|14|196|15\n");
    fprintf(file, "ул. Лесная, 11|Складской|2|4|45\n");
    fprintf(file, "наб. Реки, 7|Жилой|17|272|80\n");

    fclose(file);
    printf("Исходный файл '%s' успешно создан.\n", filename);
}

void view_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Ошибка при открытии файла для просмотра");
        return;
    }

    printf("\n--- Содержимое файла '%s' ---\n", filename);
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        // Убираем символ новой строки в конце для красивого вывода
        line[strcspn(line, "\n")] = 0;
        printf("%s\n", line);
    }
    printf("-----------------------------\n");

    fclose(file);
}
void process_file(const char *input_filename, const char *output_filename) {
    FILE *input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        perror("Ошибка при открытии исходного файла для обработки");
        return;
    }

    FILE *output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        perror("Ошибка при создании результирующего файла");
        fclose(input_file);
        return;
    }

    fprintf(output_file, "Здания со сроком эксплуатации более 50 лет:\n");
    fprintf(output_file, "--------------------------------------------------------\n");
    fprintf(output_file, "%-25s %-15s %-6s %-9s %-7s %-7s\n",
            "Адрес", "Тип", "Этажи", "Квартиры", "Экспл.", "До ремонта");
    fprintf(output_file, "--------------------------------------------------------\n");

    Building b;
    char line[256];
    int found_count = 0;
    while (fgets(line, sizeof(line), input_file)) {
        line[strcspn(line, "\n")] = 0;
        char *token = strtok(line, "|");
        if (token == NULL) continue;
        strncpy(b.address, token, MAX_ADDRESS_LEN - 1);
        b.address[MAX_ADDRESS_LEN - 1] = '\0';

        token = strtok(NULL, "|");
        if (token == NULL) continue;
        strncpy(b.type, token, MAX_TYPE_LEN - 1);
        b.type[MAX_TYPE_LEN - 1] = '\0';

        token = strtok(NULL, "|");
        if (token == NULL) continue;
        b.floors = atoi(token);

        token = strtok(NULL, "|");
        if (token == NULL) continue;
        b.apartments = atoi(token);

        token = strtok(NULL, "|");
        if (token == NULL) continue;
        b.service_life = atoi(token);
        b.years_to_repair = CAPITAL_REPAIR_PERIOD - b.service_life;
        if (b.service_life > 50) {
            fprintf(output_file, "%-25s %-15s %-6d %-9d %-7d %-7d\n",
                    b.address, b.type, b.floors, b.apartments,
                    b.service_life, b.years_to_repair);
            found_count++;
        }
    }

    if (found_count == 0) {
        fprintf(output_file, "Нет зданий, удовлетворяющих условию.\n");
    }

    fprintf(output_file, "--------------------------------------------------------\n");

    fclose(input_file);
    fclose(output_file);

    printf("Обработка завершена. Результаты сохранены в '%s'.\n", output_filename);
}


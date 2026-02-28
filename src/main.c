#include <stdio.h>
#include "buildings.h"

int main() {
    const char *initial_file = "buildings.txt";
    const char *result_file = "old_buildings.txt";
    printf("Программа для обработки данных о зданиях\n");
    printf("========================================\n");
    printf("\n[1] Создание исходного файла...\n");
    create_initial_file(initial_file);
    printf("\n[2] Просмотр содержимого исходного файла...\n");
    view_file(initial_file);
    printf("\n[3] Обработка данных и сохранение результатов...\n");
    process_file(initial_file, result_file);
    printf("\n[4] Просмотр содержимого результирующего файла...\n");
    view_file(result_file);
    printf("\nПрограмма завершена.\n");
    return 0;
}

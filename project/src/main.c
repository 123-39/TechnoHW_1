#include <stdio.h>
#include <stdlib.h>
#include "data.h"

#define ERR -1

int main() {
    printf("Set the initial size of the movie database: ");
    // Начальный размер базы (количество фильмов)
    int Base_size = 0;
    fscanf(stdin,"%i", &Base_size);
    // Начальный массив структур
    MyKinopoisk *Films = allocate_struct(Base_size);
    if (!Films) {
        fprintf(stderr, "Error: can't allocate memory!");
        free(Films);
        return ERR;
    }
    // Создаем первоначальную базу
    Create_base(Films, Base_size);
    printf("%i", Films[Base_size].Release_year);
    //Вывод базы на экран
    Output_base(Films, Base_size);
    // Счетчик элементов новой (рекомендательной) базы
    int Base_rec_size = 0;
    // Рекомендательный массив структур
    MyKinopoisk *Films_rec = allocate_struct(Base_size);
    if (!Films_rec) {
        fprintf(stderr, "Error: can't allocate memory!");
        free(Films_rec);
        return ERR;
    }
    // Рекомендация фильмов по заданным критериям
    Recomendation(Films, Base_size, Films_rec, &Base_rec_size);
    // Вывод рекомендованных фильмов
    Output_base(Films_rec, Base_rec_size);
    // Очищаем память
    free(Films);
    free(Films_rec);
    Films = 0;
    Films_rec = 0;
    return 0;
}

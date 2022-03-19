#include <stdlib.h>
#include "data.h"

// Выделение памяти
MyKinopoisk *allocate_struct(const int base_size)
{
    MyKinopoisk *p = (MyKinopoisk *) malloc(sizeof(MyKinopoisk)*base_size);
    return p;
}
// Информация о жанрах
char *Genre_list[] = {"Genre_1","Genre_2", "Genre_3", "Genre_4", "Genre_5"};
// Инициализация начальной базы
void Create_base(MyKinopoisk *Base, const int base_size) {
    double help_average_rating = 0;
    for (int i = 0; i < base_size; ++i) {
        Base[i].Movie_title = "Movie";
        Base[i].Release_year = 1922 + rand() % 101;
        help_average_rating = 2 + rand() % 4;
        Base[i].Average_rating = help_average_rating / (1 + rand() % 3);
        Base[i].Genre = Genre_list[rand() % (sizeof(Genre_list) / sizeof(Genre_list[0]))];
    }
}

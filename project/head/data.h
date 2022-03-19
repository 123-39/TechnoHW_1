#ifndef HW_1_DATA_H
#define HW_1_DATA_H

// Определение структуры
typedef struct MyKinopoisk{
    char *Movie_title;
    unsigned int Release_year;
    char *Genre;
    double Average_rating;
}MyKinopoisk;

// Функция выделения памяти
MyKinopoisk *allocate_struct(int base_size);
// Инициализация начальой базы
void Create_base(MyKinopoisk *Base, int base_size);
// Вывод базы (или нужных фильмов)
void Output_base(const MyKinopoisk *Base, int Base_size);
// Функция рекомендации фильмов
void Recomendation(const MyKinopoisk *Base, int baseSize,
                   MyKinopoisk *Films_rec, int *Base_rec_size);

// Глобальное значение данных о жанре
extern char *Genre_list[];
#endif //HW_1_DATA_H

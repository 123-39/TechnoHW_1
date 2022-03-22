#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"

// Рекомендация по диапазону оценки
void Rec_rate(const MyKinopoisk *const Base, int baseSize,
              MyKinopoisk *Films_rec, int *Base_rec_size){
    fprintf(stdout,"Enter the lower bound of the rating range : ");
    double low_rate;
    fscanf(stdin,"%lf", &low_rate);
    fprintf(stdout,"Enter the upper bound of the rating range : ");
    double up_rate;
    fscanf(stdin,"%lf", &up_rate);
    for (int i = 0; i < baseSize; ++i) {
        if ((Base[i].Average_rating >= low_rate) && (Base[i].Average_rating <= up_rate)) {
            Films_rec[*Base_rec_size] = Base[i];
            (*Base_rec_size)++;
        }
    }
}

// Рекомендация по жанру
void Rec_genre(const MyKinopoisk *const Base, int baseSize,
               MyKinopoisk *Films_rec, int *Base_rec_size){
    fprintf(stdout,"Enter your desired genre: ");
    char *genre_rec;
    genre_rec = (char*) malloc(sizeof(Base->Genre));
    fscanf(stdin,"%10s", genre_rec);
    for (int i = 0; i < baseSize; ++i) {
        if (strcmp(Base[i].Genre, genre_rec) == 0) {
            Films_rec[*Base_rec_size] = Base[i];
            (*Base_rec_size)++;
        }
    }
    free(genre_rec);
    genre_rec = 0;
}

// Рекомендация по году выпуска
void Rec_release_year(const MyKinopoisk *const Base, int baseSize,
                      MyKinopoisk *Films_rec, int *Base_rec_size){
    fprintf(stdout,"Enter your desired release year: ");
    unsigned int release_year;
    fscanf(stdin,"%ui", &release_year);
    for (int i = 0; i < baseSize; ++i) {
        if (Base[i].Release_year == release_year) {
            Films_rec[*Base_rec_size] = Base[i];
            (*Base_rec_size)++;
        }
    }
}
// Функция рекомендации фильмов
void Recomendation(const MyKinopoisk *const Base, int baseSize,
                   MyKinopoisk *Films_rec, int *Base_rec_size){
    int check = 0; // Переменная для определения рекомендации
    while (check != 4) {
        fprintf(stdout,"Recommend by rating range?  [Input: 1];\n");
        fprintf(stdout,"Recommend by genre?  [Input: 2];\n");
        fprintf(stdout,"Recommend by release year?  [Input: 3];\n");
        fprintf(stdout,"Finish?  [Input: 4];\n");
        fprintf(stdout,"Choose: ");
        fscanf(stdin,"%i", &check);
        switch (check) {
            case 1:
                Rec_rate(Base, baseSize, Films_rec, Base_rec_size);
                break;
            case 2:
                Rec_genre(Base, baseSize, Films_rec, Base_rec_size);
                break;
            case 3:
                Rec_release_year(Base, baseSize, Films_rec, Base_rec_size);
                break;
            case 4:
                break;
            default:
                fprintf(stdout,"Recommendations have not been selected. \n");
        }
    }
}

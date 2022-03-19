#include <stdio.h>
#include "data.h"

// Вывод базы (или нужных фильмов)
void Output_base(const MyKinopoisk *const Base, int Base_size){
    fprintf(stdout,"=======================================================\n");
    for (int i = 0; i < Base_size ; i++) {
        fprintf(stdout,"%s, %i, %s, %2.2f\n",Base[i].Movie_title,
               Base[i].Release_year, Base[i].Genre, Base[i].Average_rating);
    }
    fprintf(stdout,"=======================================================\n");
}

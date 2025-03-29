#include <stdio.h>
#include <string.h>

struct Year {
  int year;
  int count;
};

int main() {
  FILE * movies = fopen("./assets/filmes.txt", "r");

  char movieName[60], classfication[6];
  int year, duration;
  float spent, income, spectates, profit;

  char movieWithMostProfit[60], movieWithMostSpectates[60];
  float mostProfit = 0, mostSpectates;

  int quantityOfMovies = 0, countDuration = 0;
  float averageDuration = 0;

  const int TF_QUANTITY_OF_YEARS = 20;
  Year years[TF_QUANTITY_OF_YEARS];

  int tlQuantiyOfYears = 0;

  do {
    fscanf(movies, "%[^,],%d,%[^,],%f,%f,%d,%f\n", movieName, &year, classfication, &spent, &income, &duration, &spectates);

    profit = income - spent;

    if (profit > mostProfit) {
      mostProfit = profit;
      strcpy(movieWithMostProfit, movieName);
    }

    if (spectates > mostSpectates) {
      mostSpectates = spectates;
      strcpy(movieWithMostSpectates, movieName);
    }

    int index = 0;

    while(index < tlQuantiyOfYears && years[index].year != year)
      index++;

    if (index < tlQuantiyOfYears) {
      years[index].count++;
    } else {
      years[index].year = year;
      years[index].count = 1;
      tlQuantiyOfYears++;
    }

    countDuration += duration;
    quantityOfMovies++;
  } while((!feof(movies)));

  for(int index = 0; index < tlQuantiyOfYears; index++) {
    if (years[index].year) {
      printf("%d - %d\n", years[index].year, years[index].count);
    }
  }

  averageDuration = (float) countDuration / quantityOfMovies;

  printf("Filme com maior renda: %s (%.2f)\n", movieWithMostProfit, mostProfit);
  printf("Filme com maior taxa de espectadores: %s\n", movieWithMostSpectates);
  printf("Duração média dos filmes: %.2f\n", averageDuration);
}
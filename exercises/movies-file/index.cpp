#include <stdio.h>
#include <string.h>

struct Year {
  int year;
  int countTimes;
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

    countDuration += duration;
    quantityOfMovies++;
  } while((!feof(movies)));

  printf("%d", quantityOfMovies);

  averageDuration = (float) countDuration / quantityOfMovies;

  printf("Filme com maior renda: %s (%.2f)\n", movieWithMostProfit, mostProfit);
  printf("Filme com maior taxa de espectadores: %s\n", movieWithMostSpectates);
  printf("Duração média dos filmes: %.2f\n", averageDuration);
}
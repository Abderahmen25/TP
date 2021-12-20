#include <time.h>
#include <math.h>
#include <fstream>
#include <string>
#include "tp3.h"

#define BILLION  1000000000.0


void vector_from_file(int size, double *vect, char *filename) {
  int i;
  std::string line;
  std::fstream file;

  file.open(filename, std::ios::in);
  if (!file.is_open()) {
    printf("error reading [%s]\n", filename);
    perror(NULL);
    exit(EXIT_FAILURE);
  }

  i = 0;
  while (getline(file, line)) {
    vect[i] = std::stod(line);
    i++;
    if (i>size) {
      break;
    }
  }

  file.close();

  if (i!=size) {
    printf("error: size [%d] does not match [%d] lines read from [%s]\n", size, i, filename);
    exit(EXIT_FAILURE);
  }
}


int main(int argc, char *argv[]) {

    int size, repeat, i;
    double *vector_a, *vector_b;
    double avg_runtime, similarity;
    struct timespec start, end;

    repeat = std::atoi(argv[1]);
    size = std::atoi(argv[2]);

    vector_a = (double *) malloc(size * sizeof(*vector_a));
    vector_b = (double *) malloc(size * sizeof(*vector_a));

    vector_from_file(size, vector_a, argv[3]);
    vector_from_file(size, vector_b, argv[4]);

    avg_runtime = 0;



    printf("%.20f %.15f", similarity, avg_runtime);

    return 0;
}

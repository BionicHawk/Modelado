#include <iostream>
#include "libs/num_gen.h"
#include <vector>

int main() {
  unsigned int N = 0;
  std::vector<double> numbers = {};
  
  std::cout << "Ingrese la cantidad de numeros: ";
  std::cin >> N;
  
  numbers = Generator::generate_numbers(N);

  std::cout << "\nNumeros generados: \n\n";
  for (auto number: numbers) {
    std::cout << "\t" << number << "\n";
  }

  std::cout << "\n";
  system("pause");

}

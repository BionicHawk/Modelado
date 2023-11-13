#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include "libs/stat_nums.h"
#include "libs/num_gen.h"

void print_divider() {
  std::cout << "---------------------------\n";
}

void get_response(int* num_pointer, std::string message) {
  std::cout << message << ": ";
  std::cin >> *num_pointer;
}

void read_numbers(std::vector<double>* numbers, int length) {
  for (int i = 0; i < length; i++) {
    double number = 0.0;
    std::cout << "\tIngrese el numero #" << (i + 1) << ": ";
    std::cin >> number;
    numbers->push_back(number);
  }
}

void get_numbers(std::vector<double>* numbers, int* n) {
  std::string response = "";
  std::cout << "Si desea ingresar los numeros manualmente ingrese S, N de otra manera (se generaran los numeros): ";
  std::cin >> response;
  print_divider();

  if (response == "s" || response == "S") {
    std::cout << "\nIngrese los numeros:\n\n";
    read_numbers(numbers, *n);  
  } else {
    std::cout << "\nLos numeros generados son: \n\n";
    *numbers = Generator::generate_numbers(*n);

    for (auto number : *numbers) {
      std::cout << "\t" << number << "\n";
    }

  }
  std::cout << "\n";
  print_divider();
}

void sort_numbers(std::vector<double>* list_numbers) {
  bool error = true;
  
  while(error) {
    
    // sorting
    for (int i = 0; i < list_numbers->size() - 1; i++) {
      if (list_numbers->at(i) > list_numbers->at(i + 1)) {
	double aux = list_numbers->at(i);
	list_numbers->at(i) = list_numbers->at(i+1);
	list_numbers->at(i+1) = aux;
      }
    }

    error = false;

    for (int i = 0; i < list_numbers->size() - 1; i++) {
      if (list_numbers->at(i) > list_numbers->at(i+1)) {
	error = true;
      }
    }

  }

}

void resolve_problem(std::vector<double>* numbers, int* percent) {
  sort_numbers(numbers);
  std::string to_print = "";
  double max_num = 0.0;
  
  std::cout << "i\txi\t\tF(xi) = i/n\t\tDn = Max|F(xi) - xi|\n\n";

  for (int i = 0; i < numbers->size(); i++) {
    std::string fraction = std::to_string((i + 1)) + "/" + std::to_string(numbers->size());
    double fraction_result = (double)(i + 1) / (double)numbers->size();
    fraction += " = " + std::to_string(fraction_result);

    double delta = std::abs(fraction_result - numbers->at(i));
    if (delta > max_num) max_num = delta;

    to_print += std::to_string(i + 1) + "\t" + std::to_string(numbers->at(i)) + "\t" + fraction + "\t\t" + std::to_string(delta) + "\n";
    
  }

  std::cout << to_print << "\n";

  print_divider();

  StatSize statSize;
  double d = statSize.get_stat(numbers->size(), *percent);

  std::cout << "d" << *percent << "%, " << numbers->size() << " = " << d << "\n";
  std::cout << max_num << " < " << d;

  if (max_num < d) {
    std::cout << ", se cumple por lo que los numeros son aceptados\n";
  } else {
    std::cout << ", no se cumple por lo que los numeros no son aceptados\n";
  }

}

int main() {
  int n = 0;
  int percent = 0;
  std::vector<double> numbers = {};

  get_response(&n, "Ingrese N");
  get_response(&percent, "Ingrese alfa %: ");
  print_divider();

  get_numbers(&numbers, &n);
  resolve_problem(&numbers, &percent);
  system("pause");
}

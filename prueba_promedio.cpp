#include <cctype>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <vector>
#include <string>
#include "libs/num_gen.h"
#include "libs/normal_dist.h"
#include <math.h>
#include <random>

void print_divider() {
  std::cout << "---------------------------\n";
}

void read_numbers(std::vector<double>* list, int length) {
  for(int i = 0; i < length; i++) {
    double num;
    std::cout << "\tIngrese el numero #" << (i + 1) << ": ";
    std::cin >> num;
    list->push_back(num);
  }
}

void get_percent(uint16_t* num_ptr) {
  uint16_t response = 0;
  std::cout << "Ingrese el porcentaje %: ";
  std::cin >> response;
  *num_ptr = 100 - response;

  std::cout << *num_ptr << "\n";
}

void get_numbers(std::vector<double>* numbers) {
  unsigned int n = 0;
  std::cout << "Ingrese la cantidad de numeros: ";
  std::cin >> n;
  std::string response = "";
  std::cout << "Si desea insertar los numeros manualmente ingrese S, N de otra forma (se generaran los numeros): ";
  std::cin >> response;
  print_divider();
  if (response == "s" || response == "S") {
      std::cout << "\nIngrese los numeros:\n\n";
      read_numbers(numbers, n);
  } else {
      std::cout << "\nNumeros generados: \n\n";
      *numbers = Generator::generate_numbers(n);
      for (auto number : *numbers) {
	std::cout << "\t" << number << "\n";
      }
  }
  std::cout << "\n";
}

double get_sumatory(std::vector<double>* numbers) {
  double sumatory = 0.0;
  for (auto number : *numbers) sumatory += number;
  std::cout << "Sumatoria de x: " << sumatory << "\n";
  return sumatory;
}

double get_avg(std::vector<double>* numbers) {
  return get_sumatory(numbers) / numbers->size();
}

double get_init_z(std::vector<double>* numbers) {
  double average = get_avg(numbers);
  std::cout << "El promedio de x: " << average << "\n";
  std::cout << "N: " << numbers->size() << "\n";
  double first_root = sqrt(numbers->size());
  double second_root = sqrt(1.0 / 12.0);
  double first_op = average - 0.5;
  double above_op = first_op * first_root;
  return abs(above_op / second_root);
}

double get_last_z(Table* table, uint16_t* percent) {
  double actual_percent = (double)*percent / 100.0;
  std::cout << "Porcentaje real: " << actual_percent << "%\n";
  double number_to_look = actual_percent / 2;
  Position position = table->findValuePosition(number_to_look);
  double z = position.x + position.y;
  return z;
}

void resolve_problem(std::vector<double>* numbers, uint16_t* percent) {
  Table table;
  double z0 = get_init_z(numbers);
  double zLast = get_last_z(&table, percent);
  print_divider();
  std::cout << z0 << " < " << zLast;
  if (z0 < zLast) {
    std::cout << ", se cumple por lo que se aceptan los numeros\n";
  } else {

    std::cout << ", no se cumple por lo que no se aceptan los numeros\n";
  }
}

int main() {
  uint16_t percent = 0;
  std::vector<double> numbers = {};

  get_percent(&percent);
  get_numbers(&numbers);
  
  print_divider();
  resolve_problem(&numbers, &percent);
  system("pause");

  return 0;
}

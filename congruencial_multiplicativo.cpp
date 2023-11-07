#include <cmath>
#include <cstdint>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>

bool isBinary(int* m) {
  uint32_t max_value = (uint32_t)pow(2, 16);
  std::vector<uint32_t> binaries = {};
  while (max_value != 1) {
    max_value /= 2;
    binaries.push_back(max_value);
  }
  for (auto value : binaries) {
    if(value == *m) return true;
  }
  return false;
}

void get_responses(int* var_reference, std::string msg) {
  std::cout << msg << ": ";
  std::cin >> *var_reference;
}

uint8_t get_power(int* m) {
  std::string num_str = std::to_string(*m);
  return num_str.length() - 1;
}

void resolve_problem(int* a, int* x, int* m) {

  int pe = 0;
  bool finished = false;
  int original_x = *x;

  if(isBinary(m)) {
    pe = *m / 4;
  } else {
    int power = get_power(m);
    if(power >= 5) {
      pe = *m * (int)std::pow(10, power - 2);
    } else {
      pe = ((int)std::pow(5, power - 1)) * (4);
    }
  }

  for(int i = 0; i < pe; i++) {
    std::string to_print = std::to_string((i + 1)) + "\t";
    to_print += std::to_string(*x) + "\t";

    double result = (double)(*a * *x) / (double)*m;
    int integer_value = (int)result;
    result -= integer_value;

    *x = (int)round(result * *m);
    std::string fraction = std::to_string(*x) + "/" + std::to_string(*m);

    to_print += std::to_string(integer_value) + " + " + fraction + "\t";
    to_print += std::to_string(*x) + "\t" + fraction + " = " + std::to_string(result);

    std::cout << to_print << "\n";
    if(i == pe - 1 && *x == original_x) finished = true;
    if(i != 0 && *x == original_x) break;
  }

  std::string message = "Generador congruencial multiplicativo ";

  if(finished) {
    message += "confiable";
  }else{
    message += "no confiable";
  }
  std::cout << message << "\n";

}

int main() {
  int a = 0;
  int x = 0;
  int m = 0;


  get_responses(&a, "Dame el valor de a");
  get_responses(&x, "Dame el valor de x");
  get_responses(&m, "Dame el valor de m");

  resolve_problem(&a, &x, &m);
}

#include <cmath>
#include <iostream>
#include <string>

void get_reponses(int *int_var, std::string msg) {
  std::cout << msg << ": ";
  std::cin >> *int_var;
}

void show_problem_header(int* a, int* x, int* c, int* m) {

  std::string to_print = "\nResolviendo el problema con los siguientes valores: ";
  to_print += "a: " + std::to_string(*a)+ ", ";
  to_print += "x: " + std::to_string(*x)+ ", ";
  to_print += "c: " + std::to_string(*c)+ ", ";
  to_print += "m: " + std::to_string(*m)+ "\n";
  std::cout << to_print;
}

void resolve_problem(int* a, int* x, int* c, int* m) {
  int original_x = *x;
  bool finished = false;
    
  std::cout << "\nn\tx0\t(ax0 + c) mod (m)\tx0 + 1\tNum. Rectangulares\n";

  for(int i = 0; i < *m; i++) {
    std::string to_print = std::to_string((i + 1)) + "\t";
    
    to_print += std::to_string(*x) + "\t";

    double result = (double)((*a * *x) + *c) / (double)*m;
    int integer_value = (int)result;
    result -= integer_value;
    *x = (int)round(result * *m);
    
    std::string fraction = std::to_string(*x) + "/" + std::to_string(*m);

    to_print += std::to_string(integer_value) + " + " + fraction + "\t\t";
    to_print += std::to_string(*x) + "\t";
    to_print += fraction + " = " + std::to_string(result);

    std::cout << to_print << "\n";

    if(i == *m - 1 && *x == original_x) finished = true;
    if(i != 0 && *x == original_x) break;
  }

  std::string message = "Generador congruencial mixto ";
  if(finished) {
    message += "confiable";
  } else {
    message += "no confiable";
  }
  
  std::cout << "\n" << message << "\n";
  
}

int main() {
  int a = 0;
  int x = 0;
  int c = 0;
  int m = 0;

  get_reponses(&a, "Dame el valor de a");  
  get_reponses(&x, "Dame el valor de x");  
  get_reponses(&c, "Dame el valor de c");  
  get_reponses(&m, "Dame el valor de m");

  show_problem_header(&a, &x, &c, &m);
  resolve_problem(&a, &x, &c, &m);
  system("pause");

  return 0;
}

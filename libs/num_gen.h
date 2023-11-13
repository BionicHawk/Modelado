#include <vector>
#include <cstdlib>
#include <ctime>

class Generator {
  public:
    static std::vector<double> generate_numbers(int length) {
      std::vector<double> list_numbers = {};
      srand((unsigned) time(NULL));
      
      for(int i = 0; i < length; i++) {
	double num = rand() % 100000;
	num = num / 100000;
	list_numbers.push_back(num);
      }
      return list_numbers;
    }
};

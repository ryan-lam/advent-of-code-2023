#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

int main() {
  std::ifstream file("input.txt");
  std::string line;
  std::map<std::string, int> numbers{
      {"0", 0},   {"1", 1},     {"2", 2},     {"3", 3},    {"4", 4},
      {"5", 5},   {"6", 6},     {"7", 7},     {"8", 8},    {"9", 9},
      {"one", 1}, {"two", 2},   {"three", 3}, {"four", 4}, {"five", 5},
      {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}};
  int res = 0;

  while (std::getline(file, line)) {
    int first_digit_posn = line.length();
    int last_digit_posn = 0;
    int first_digit = 0;
    int last_digit = 0;

    for (auto const& [key, value] : numbers) {
      int first_pos = line.find(key);
      int last_pos = line.rfind(key);
      if (first_pos == -1) {
        continue;
      }
      if (first_pos <= first_digit_posn) {
        first_digit_posn = first_pos;
        first_digit = value;
      }
      if (last_pos >= last_digit_posn) {
        last_digit_posn = last_pos;
        last_digit = value;
      }
    }

    int calibration_val = ((first_digit)*10) + (last_digit);
    res += calibration_val;
    // std::cout << calibration_val << std::endl;
  }

  std::cout << res << std::endl;
}

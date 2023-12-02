#include <fstream>
#include <iostream>
#include <string>

int main() {
  std::ifstream file("input.txt");
  std::string line;
  int res = 0;

  while (std::getline(file, line)) {
    int line_len = line.length();

    for (int i = 0; i < line_len; i++) {
      if ('0' <= line[i] && line[i] <= '9') {
        int tens = (line[i] - '0') * 10;
        res += tens;
        break;
      }
    }

    for (int i = line_len - 1; i >= 0; i--) {
      if ('0' <= line[i] && line[i] <= '9') {
        int ones = line[i] - '0';
        res += ones;
        break;
      }
    }

    // std::cout << res << std::endl;
    // res = 0;
  }

  std::cout << res << std::endl;
}

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

// fewest number of cubes of each color that could have been in the bag to make
// the game possible The power of a set of cubes is equal to the numbers of red,
// green, and blue cubes multiplied together

void fewest_cubes(std::string& set_str, int& min_red, int& min_green,
                  int& min_blue) {
  int count{};
  std::string colour{};
  std::istringstream iss{set_str};
  while (!iss.eof()) {
    iss >> count >> colour;
    if (colour == "red") {
      min_red = std::max(min_red, count);
    } else if (colour == "green") {
      min_green = std::max(min_green, count);
    } else if (colour == "blue") {
      min_blue = std::max(min_blue, count);
    }
  }
}

int power_of_set(std::string& game_str) {
  int set_index_start{0};
  int min_red{0}, min_blue{0}, min_green{0};
  for (size_t i = 0; i < game_str.length(); i++) {
    if (game_str[i] == ';') {
      std::string set_str =
          game_str.substr(set_index_start, i - set_index_start);
      fewest_cubes(set_str, min_red, min_green, min_blue);
      set_index_start = i + 1;
    }
  }
  //   std::cout << min_red << " " << min_green << " " << min_blue << std::endl;
  return min_red * min_green * min_blue;
}

int main() {
  std::ifstream file{"input.txt"};
  std::string game{};
  int sum_of_powers{};

  while (std::getline(file, game)) {
    // Format string before parsing
    size_t colon_index = game.find(":");  // find index of colon
    game = game.substr(colon_index + 2);  // colon + 2 to offset whitespace
    game.erase(std::remove(game.begin(), game.end(), ','),
               game.end());  // remove commas
    game += ";";             // Add semicolon to parse easier

    sum_of_powers += power_of_set(game);
  }

  std::cout << sum_of_powers << std::endl;
}

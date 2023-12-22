#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

// which games would have been possible if the bag contained only 12 red cubes,
// 13 green cubes, and 14 blue cubes

bool verify_set(std::string& set_str) {
  int count{};
  std::string colour{};
  std::istringstream iss{set_str};
  while (!iss.eof()) {
    iss >> count >> colour;
    if ((colour == "red" && count > 12) || (colour == "green" && count > 13) ||
        (colour == "blue" && count > 14)) {
      return false;
    }
  }
  return true;
}

bool verify_game(std::string& game_str) {
  int set_index_start = 0;
  for (size_t i = 0; i < game_str.length(); i++) {
    if (game_str[i] == ';') {
      std::string set_str =
          game_str.substr(set_index_start, i - set_index_start);
      if (verify_set(set_str) == false) {
        return false;
      };
      set_index_start = i + 1;
    }
  }
  return true;
}

int main() {
  std::ifstream file{"input.txt"};
  std::string game{};
  int curr_game{};
  int game_id_sum{};

  while (std::getline(file, game)) {
    curr_game++;

    // Format string before parsing
    size_t colon_index = game.find(":");  // find index of colon
    game = game.substr(colon_index + 2);  // colon + 2 to offset whitespace
    game.erase(std::remove(game.begin(), game.end(), ','),
               game.end());  // remove commas
    game += ";";             // Add semicolon to parse easier

    if (verify_game(game) == true) {
      game_id_sum += curr_game;
    }
  }

  std::cout << game_id_sum << std::endl;
}

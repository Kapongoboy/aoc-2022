#include <iostream>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <map>
#include <stdexcept>
#include <string>
#include <tuple>
#include <vector>

std::vector<std::string> readfile(){
  std::ifstream inputdata ("./input.txt");
  std::string linedata;
  std::vector<std::string> results;
  if (inputdata.is_open()) {
    while (inputdata) {
      std::getline(inputdata, linedata);
      results.push_back(linedata);
    }
  }
  return results;
};

int main (int argc, char *argv[])
{
  std::vector<std::string> data = readfile();
  // std::vector<std::string> data{"A Y", "B X", "C Z"};

  std::map<char, int> choice_map{{'X', 1}, {'Y', 2}, {'Z', 3}};
  std::map<std::string, int> round_map{
    {"A X", 3},
    {"B X", 1},
    {"C X", 2},
    {"A Y", 4},
    {"B Y", 5},
    {"C Y", 6},
    {"A Z", 8},
    {"B Z", 9},
    {"C Z", 7},
  };
  int score = 0;

  for (std::string i: data) {
    score += round_map[i];
  }

  std::cout << "the total score was: " << score;
  return 0;
}

#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <stdexcept>
#include <string>
#include <tuple>
#include <vector>
#include <cmath>

std::vector<std::string> readfile(){
  std::ifstream inputdata ("./input.txt");
  std::string linedata;
  std::vector<std::string> data;
  if (inputdata.is_open()) {
    while (inputdata) {
      std::getline(inputdata, linedata);
      data.push_back(linedata);
    }
  }
  return data;
};

int main (int argc, char *argv[])
{
  std::vector<std::string> data{"vJrwpWtwJgWrhcsFMMfFFhFp", "jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL", "PmmdzqPrVvPwwTWBwg", "wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn", "ttgJtRGJQctTZtZT", "CrZsJsPPZsGzwwsLwLmpwMDw"};

  std::map<char, int> priority_map{{}};
  int priority = 1;
  for (int i = int('a'); i <= int('z'); i++) {
    priority_map[char(i)] = priority;
    priority++;
    // std::cout << char(i) << "=" << priority_map[char(i)] << '\n';
  }
  for (int i = int('A'); i <= int('Z'); i++) {
    priority_map[char(i)] = priority;
    priority++;
    // std::cout << char(i) << "=" << priority_map[char(i)] << '\n';
  }
  
  int priority_sum = 0;
  for (std::string rucksack: data) {
    std::string compartment_one = rucksack.substr(0, std::floor(static_cast<int>(rucksack.size())/2));
    std::string compartment_two = rucksack.substr(std::floor(static_cast<int>(rucksack.size())/2));
    bool first_run = true;
    for (char i: compartment_one) {
      if (std::find(std::begin(compartment_two), std::end(compartment_two), i) != std::end(compartment_two) && first_run) {
        std::cout << "the letter " << i << " is in both compartments" << '\n';
        std::cout << "the map for this value is " << i << " = " << priority_map[i] << '\n';
        priority_sum += priority_map[i];
        first_run = false;
      };
    };
  };
  
  std::cout << priority_sum;
  return 0;
}

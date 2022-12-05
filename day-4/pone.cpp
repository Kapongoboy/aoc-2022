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
  std::vector<std::string> data{"2-4,6-8", "2-3,4-5", "5-7,7-9", "2-8,3-7", "6-6,4-6", "2-6,4-8"};
  for (std::string i: data) {
    std::string item_one = i.substr(0, i.find(","));
    std::string item_two = i.substr(i.find(",")+1);
    char range_start_one = item_one[0];
    char range_start_two = item_two[0];
    char range_end_one = item_one[1];
    char range_end_two = item_two[0];
    int range_one_length = int(range_end_one) - int(range_start_one);
    int range_two_length = int(range_end_two) - int(range_start_two);
    if (range_one_length <= range_two_length) {
      for (int i = int(range_start_one); i < int(range_end_one) + 1; i++) {

      };
    }
  };
  return 0;
}

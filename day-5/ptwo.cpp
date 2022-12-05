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

std::map<int, std::string> move(int amount, int from, int to, std::map<int, std::string> crates) {
  std::string buffer;
  for (int i = 0; i < amount; i++) {
    buffer += crates[from][crates[from].size()-1];
    crates[from].pop_back();
  };
    // crates[to] = crates[to] + crates[from][crates[from].size()-1];
  std::reverse(buffer.begin(), buffer.end());
  crates[to] = crates[to] + buffer;
  return crates;
};

std::string message(std::map<int, std::string> crates) {
  std::string message_string = "";
  for (int i = 0; i < crates.size(); i++) {
    message_string += crates[i][crates[i].size()-1];
  };
  return message_string;
};

auto DataTreatment(std::vector<std::string> data) {
  std::map<int, std::string> treatment{{}};
  int index[9] = {1, 5, 9, 13, 17, 21, 25, 29, 33};
  int cargo_hold = 0;
  for (int l = 0; l < 8; l++) {
    for (int i: index) {
      cargo_hold++;
      if (data[l][i] != ' ') {
        treatment[cargo_hold] = treatment[cargo_hold] + data[l][i];
      };
    };
    cargo_hold = 0;
  };
  for (int y = 1; y < treatment.size(); y++) {
    std::reverse(treatment[y].begin(), treatment[y].end());
  };
  std::cout << "data treatment done" << '\n';
  return treatment;
};

std::vector<std::vector<int>> GenerateInstructions(std::vector<std::string> data) {
  std::cout << "Generate instructions start" << '\n';
  std::vector<std::vector<int>> instructions;
  int index = 0;
  std::string amount, from, to;
  std::vector<int> holder_vector;
  for (std::string line: data) {
    amount = line.substr(0, line.find('f')-1);
    holder_vector.push_back(std::stoi(amount.substr(amount.find(" "))));
    from = line.substr(line.find('f'), line.find('t')-line.find('f')-1);
    holder_vector.push_back(std::stoi(from.substr(from.find(" "))));
    to = line.substr(line.find('t'), line.find('t') - line.find('t')-line.find('f'));
    holder_vector.push_back(std::stoi(to.substr(to.find(" "))));
    for (auto item: holder_vector) {
      std::cout << item << " ";
    };
    std::cout << '\n';
    instructions.push_back(holder_vector);
    holder_vector.clear();
    index++;
  };
  std::cout << "size: " << instructions.size() << '\n';
  return instructions;
};

int main (int argc, char *argv[])
{
  std::vector<std::string> data = readfile();
  std::map<int, std::string> crates = DataTreatment(data);
  // std::map<int, std::string> crates{{1, "ZN"}, {2, "MCD"}, {3, "P"}};
  // std::vector<std::vector<int>> instructions{{1, 2, 1}, {3, 1, 3}, {2, 2, 1}, {1, 1, 2}};
  std::vector<std::vector<int>> instructions = GenerateInstructions(std::vector<std::string>(data.begin()+10, data.end()-1));
  std::cout << "instructions printed" << '\n';
  std::map<int, std::string> crate_buffer;
  for (auto instruction: instructions) {
    std::cout << "move " << instruction[0] << " from " << instruction[1] << " to " << instruction[2] << '\n';
    crate_buffer = move(instruction[0], instruction[1], instruction[2], crates);
    crates = crate_buffer;
  };

  std::cout << "crate operation complete" << '\n';
  std::string final_message = message(crates);
  std::cout << final_message;
  return 0;
}


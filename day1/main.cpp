#include <bits/stdc++.h>

int puzzle_a(std::ifstream &input_file) {
  int dial = 50;
  int num_zeros = 0;
  const std::regex op_regex("(L|R)(\\d*)");

  for (std::string line; std::getline(input_file, line);) {
    char op;
    int val;

    std::smatch matches;
    std::regex_match(line, matches, op_regex);
    op = (matches[1].str())[0];
    val = std::atoi(matches[2].str().c_str());

    // always (val % 100) to get remainder
    val = val % 100;

    if (op == 'R') {
      dial += val;
    } else {
      dial -= val;
    }
    dial = (dial >= 100 ? (dial % 100) : dial);
    dial = (dial < 0 ? (100 + dial) : dial);

    if (dial == 0) {
      ++num_zeros;
    }
  }

  return num_zeros;
}

int puzzle_b(std::ifstream &input_file) {
  int dial = 50;
  int num_zeros = 0;
  const std::regex op_regex("(L|R)(\\d*)");

  for (std::string line; std::getline(input_file, line);) {
    char op;
    int val;

    std::smatch matches;
    std::regex_match(line, matches, op_regex);
    op = (matches[1].str())[0];
    val = std::atoi(matches[2].str().c_str());

    // first add all clicks from 100n rotations
    num_zeros += val / 100;

    // now mod by 100
    val = val % 100;

    int dist_to_zero;
    if (op == 'R') {
      dist_to_zero = 100 - dial;
      dial += val;
    } else {
      dist_to_zero = dial;
      dial -= val;
    }
    dial = (dial >= 100 ? (dial % 100) : dial);
    dial = (dial < 0 ? (100 + dial) : dial);

    if (dial == 0) {
      ++num_zeros;
    } else if (val > dist_to_zero && dist_to_zero != 0) {
      ++num_zeros;
    }
  }

  return num_zeros;
}

int main(int argc, char *argv[]) {
  std::ifstream input_file;
  input_file.open(argv[2]);

  int result;
  if (argv[1][0] == 'a') {
    result = puzzle_a(input_file);
  } else {
    result = puzzle_b(input_file);
  }
  std::cout << result << '\n';

  return 0;
}
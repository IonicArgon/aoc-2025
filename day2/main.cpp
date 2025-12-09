#include <bits/stdc++.h>

using pairs_t = std::vector<std::pair<long long, long long>>;

void parse_pairs(std::ifstream &input_file, pairs_t &pairs) {
  const std::regex pair_regex("(\\d+)-(\\d+)\\s*");
  for (std::string line; std::getline(input_file, line, ',');) {
    std::smatch matches;
    std::regex_match(line, matches, pair_regex);

    long long start = std::atoll(matches[1].str().c_str());
    long long end = std::atoll(matches[2].str().c_str());
    auto pair = std::make_pair(start, end);
    pairs.push_back(pair);
  }
}

long long part_a(pairs_t &pairs) {
  const std::regex number_regex("(\\d+)\\1");

  long long sum = 0;
  for (auto pair : pairs) {
    for (long long i = pair.first; i <= pair.second; ++i) {
      if (std::regex_match(std::to_string(i), number_regex)) {
        sum += i;
      }
    }
  }

  return sum;
}

long long part_b(pairs_t &pairs) {
  const std::regex number_regex("(\\d+)\\1+");

  long long sum = 0;
  for (auto pair : pairs) {
    for (long long i = pair.first; i <= pair.second; ++i) {
      if (std::regex_match(std::to_string(i), number_regex)) {
        sum += i;
      }
    }
  }

  return sum;
}

int main(int argc, char *argv[]) {
  std::ifstream input_file;
  input_file.open(argv[2]);
  pairs_t pairs;

  parse_pairs(input_file, pairs);

  long long result;

  if (argv[1][0] == 'a') {
    result = part_a(pairs);
  } else {
    result = part_b(pairs);
  }

  std::cout << result << '\n';

  return 0;
}

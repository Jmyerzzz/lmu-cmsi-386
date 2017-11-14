#include <iostream>
#include <cassert>
#include <string>

using namespace std;

struct Adder {
private:
  std::string final_string = "";
public:
  Adder(std::string s = ""): final_string(s) {}

  Adder operator()(std::string value) {
    return Adder(final_string + " " +value);
  }

  std::string operator()() {
    if (final_string.length()){
        final_string = final_string.substr(1);
    }
    return final_string;
  }
};

Adder f;

int main() {
  assert(f() == "");
  assert(f("hi")() == "hi");
  assert(f("hi")("there")() == "hi there");
  assert(f("hi")("there")("billy")("bob")() == "hi there billy bob");
  assert(f("yo")("yo")("yo")("yo")("yo")() == "yo yo yo yo yo");
  cout << "All tests passed!\n";
}

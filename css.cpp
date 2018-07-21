#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
  int x = strlen(argv[1]), y = strlen(argv[2]);
  for (int i = 0; i < x; i++) {
    cout << "i: " << i << endl;
  }
}

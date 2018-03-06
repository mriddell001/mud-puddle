/*
Filename: main.cpp
Name: Matthew Riddell-Ide
Contents: This file contains the main functions of control for the SRANN.
*/
#include <fstream>
#include "ANN.h"

/**
 * main - This function accepts user input in the form of command line arguments
 *        to read three files. The first being the setup instructions for the
 *        neural network. This includes a flag for network type (default values
 *        vs. calculated values) the size of the input layer, the output layer,
 *        the number of hidden layers and their respective size.
 *
 *        The second being the test cases. This file should be kept in memory
 *        for testing and training purposes. The file format starts with two int
 *        values that indicate the number of true and false test cases. Each
 *        case will have a length of the input layer and the output layer.
 *
 *        The third being the instruction set. This file defines how the SRANN
 *        is trained and what actions are to be taken by the network.
 * @param {INT} argc - Number of arguments.
 * @param {CHAR} argv - An array containing the arguments.
 * @returns {INT} - returns value of zero on sucessful exit.
 */
int main(int argc, char const *argv[]) {
  std::ifstream input_stream (argv[1], std::ifstream::in);

  int one=0, two=0, three=0, four=0;
  if (input_stream.is_open()) {
    input_stream >> one >> two >> three >> four;
  }

  ANN ann = ANN(one, two, three, four);


  return 0;
}

/*
Filename: main.cpp
Name: Matthew Riddell-Ide
Contents: This file contains the main functions of control for the SRANN.
*/
#include <fstream>
#include "ANN.h"

/**
 * main - This function accepts user input in the form of command line arguments
 *        to read three files.
 *
 *        Input Stream Format:
 *        The first file is the setup instructions for the neural network. The
 *        first value is a flag to indicate if the values should be the default
 *        values or previously calculated values. When this flag is false, the
 *        format of the stream is the size of the input layer, number of hidden
 *        layers, their respective sizes, and the size of the output layer.
 *
 *        When the flag for the calculated values is true, then the format of
 *        the stream is the size of the input layer, the weight of each node in
 *        the input layer, the number of edges to the next layer, the array of
 *        edge weights to the next layer, and so on until the output layer.
 *
 *        Test Stream Format:
 *        The second file is the test cases. This file should be kept in memory
 *        for testing and training purposes. The file format starts with two int
 *        values that indicate the number of true and false test cases. Each
 *        case will have a length of the input layer and the output layer then
 *        followed by the input layer values and expected output layer values.
 *
 *        Instruction Stream Format:
 *        The third file is the instruction set. This file defines how the SRANN
 *        is trained and what actions are to be taken by the network. The file
 *        format starts with a flag indicating what type of instructions will
 *        follow. This will define if the test cases are selected randomly or in
 *        a specific distribution. If the number of iterations is a fixed
 *        integer or if it needs to reach an Acceptable Error level as
 *        represented by an Euclidean Distance from the expected values.
 *
 * @param {INT} argc - Number of arguments.
 * @param {CHAR} argv - An array containing the arguments.
 * @returns {INT} - returns value of zero on sucessful exit.
 */
int main(int argc, char const *argv[]) {
  std::ifstream input_stream (argv[1], std::ifstream::in);
  std::ifstream test_stream (argv[2], std::ifstream::in);
  std::ifstream instruction_stream (argv[3], std::ifstream::in);

  int nn_input[4];
  int input_flag, t_true, t_false;

  if (input_stream.is_open()) {
    input_stream >> input_flag;
    if (input_flag) {
      /* code */
    }
    else {
      input_stream >> nn_input[0] >> nn_input[1] >> nn_input[2] >> nn_input[3];
    }
  }

  ANN ann = ANN(nn_input);

  if (test_stream.is_open()) {
    test_stream >> t_true >> t_false;
  }


  return 0;
}

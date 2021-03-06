/*
Filename: ANN.h
Name: Matthew Riddell-Ide
Contents: This file contains the header for the ANN.
Functions:
  ANN - This constructor is passed four int values as its parameter, the
        first element is the size of the input layer, the second is the number
        of hidden layers, the third is the size of the hidden layers, the last
        element is the size of the output layer.
  ~ANN - This destructor frees all memory reserved by the class ANN.
*/

//ANN.h
#ifndef ANN_H
#define ANN_H

#include <iostream>
#include "Node.h"

class ANN {
public:
  ANN(int in[4]);
  ~ANN();
  void auto_refine(std::istream &stream);
  void testing_handler(std::istream &stream);

private:
  bool init();
  bool prime_input(std::istream &stream);
  void input_layer_creation(int a);
  void hidden_layer_creation(int b, int d);
  void output_layer_creation(int b, int c, int d);

  std::vector<Node*> ann_i;   //Vector of input nodes.
  std::vector<Node*> ann_h;   //Vector of hidden nodes.
  std::vector<Node*> ann_o;   //Vector of output nodes.
  int m_input_size;
  int m_hidden_layers;
  int m_hidden_size;
  int m_output_size;
};

#endif // ANN_H

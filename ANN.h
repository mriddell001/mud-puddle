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

#include <vector>
#include "Node.h"

class ANN {
public:
  ANN(int in[4]);
  ~ANN();
private:
  void init();

  std::vector<Node*> ann_i;
  std::vector<Node*> ann_o;
  int m_input_size;
  int m_hidden_layers;
  int m_hidden_size;
  int m_output_size;
};

#endif // ANN_H

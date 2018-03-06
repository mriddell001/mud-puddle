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
  ANN(int one, int two, int three, int four);
  ~ANN();

  std::vector<Node*> m_input_nodes;       //Pointers to nodes in next layer.
  std::vector<Node*> m_hidden_nodes;       //Pointers to nodes in next layer.
  std::vector<Node*> m_output_nodes;       //Pointers to nodes in next layer.
  int m_input_size;
  int m_hidden_layers;
  int m_hidden_size;
  int m_output_size;
};

#endif // ANN_H

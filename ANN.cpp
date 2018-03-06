/*
Filename: ANN.cpp
Name: Matthew Riddell-Ide
Contents: This file contains the main functions of control for the ANN.
Functions:
  ANN - This constructor is passed four int values as its parameter, the
        first element is the size of the input layer, the second is the number
        of hidden layers, the third is the size of the hidden layers, the last
        element is the size of the output layer.
  ~ANN - This destructor frees all memory reserved by the class ANN.
*/
#include "ANN.h"
#include "Node.h"
#include <vector>

using namespace std;

ANN::ANN(int one, int two, int three, int four)
{
  m_input_size = one;
  m_hidden_layers = two;
  m_hidden_size = three;
  m_output_size = four;

  for (int i = 0; i < m_output_size; i++) {
    Node* node = new Node(2);
    m_output_nodes.push_back(node);
  }

  for (int i = 0; i < m_hidden_layers; i++) {
    for (int j = 0; j < m_hidden_size; j++) {
      Node* node = new Node(1);
      m_hidden_nodes.push_back(node);
    }
  }

  for (int i = 0; i < m_input_size; i++) {
    Node* node = new Node(0);
    m_input_nodes.push_back(node);
  }



}

ANN::~ANN()
{

}

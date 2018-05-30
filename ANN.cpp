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

ANN::ANN(int in[4])
{
  m_input_size = in[0];
  m_hidden_layers = in[1];
  m_hidden_size = in[2];
  m_output_size = in[3];

  bool init_success = init();
  if(!init_success) {
    cout << "There has been a problem with the init function.\n";
  }
}

ANN::~ANN()
{

}

/**
 * init - This function serves to initialize the nodes in the ANN. This version
 *        is the primative version. Ultimately, this should be able to use
 *        recursion to automatically set every value.
 *
 * Assumptions: On start, this function assumes there are valid values for the
 * size of the layers and number of layers. It also assumes each hidden layer is
 * of equal size. On finish, it is to be assumed that the ANN has been
 * completely initialized and the input & output layers are set and can be
 * accessed.
 *
 * Testing status: Untested.
 */
bool ANN::init() {
  Node *tmp, *pmt;
  int a = m_input_size, b = m_hidden_size, c = m_output_size, d = m_hidden_layers;

  //Initialize Input Nodes
  for (int i = 0; i < a; i++) {
    tmp = new Node();
    ann_i.push_back(tmp);
  }

  //For each layer in the ANN.
  for (int i = 0; i < d; i++) {
    //For each node in each layer.
    for (int j = 0; j < b; j++) {
      tmp = new Node();
      ann_h.push_back(tmp);
      if (i) {
        int l = (i - 1) * b;
        for (int k = 0; k < b; k++) {
          pmt = ann_h[l+k];
          (*pmt).m_edges.push_back(tmp);
          (*pmt).m_edgeWeight.push_back(0.5);
        }
      }
      else {
        //This is for connecting the input layer to the first hidden layer.
        for (vector<Node*>::iterator it = ann_i.begin() ; it != ann_i.end(); ++it) {
          (*it)->m_edges.push_back(tmp);
          (*it)->m_edgeWeight.push_back(0.5);
        }
      }
    }
  }

  //This creates and connects the output layer to the last hidden layer.
  int l = (d*b)-b;
  for (int i = 0; i < c; i++) {
    tmp = new Node();
    ann_o.push_back(tmp);
    for (int j = 0; j < b; j++) {
      pmt = ann_h[l+j];
      (*pmt).m_edges.push_back(tmp);
      (*pmt).m_edgeWeight.push_back(0.5);
    }
  }
  return true;
}

bool ANN::prime_input(istream &stream) {
  double tmp;
  for (vector<Node*>::iterator it = ann_i.begin() ; it != ann_i.end(); ++it) {
    stream >> tmp;
    (*it)->m_weight = tmp;
  }
  return true;
}

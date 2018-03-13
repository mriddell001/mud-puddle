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

  init();
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
 * size of the layers and number of layers. On finish, it is to be assumed that
 * the ANN has been completely initialized and the input & output layers are set
 * and can be accessed.
 *
 * Testing status: Untested.
 */
void ANN::init() {
  Node *tmp, *m_parent;
  int a, b, c, d;
  a = m_input_size;
  b = m_hidden_size;
  c = m_output_size;
  d = m_hidden_layers;

  //Init Input Nodes
  for (int i = 0; i < a; i++) {
    tmp = new Node();
    tmp->m_parent = NULL;
    ann_i.push_back(tmp);
  }

  m_parent = ann_i[0];

  //For each layer in the ANN.
  for (int i = 0; i < d+1; i++) {
    int l, m;

    if (!i) {l = b;m = a;}
    else if (i == d) {l = c;m = b;}
    else {l = m = b;}

    //For each node in the next layer.
    for (int j = 0; j < l; j++) {
      tmp = new Node();
      //For each node in the current layer.
      for (int k = 0; k < m; k++) {
        if (i) {
          tmp->m_parent = m_parent->m_edges[0];
          m_parent->m_edges[k]->m_edges.push_back(tmp);
          m_parent->m_edges[k]->m_edgeWeight.push_back(0.5);
          if (i == d) {
            ann_o.push_back(tmp);
          }
        }
        else {
          tmp->m_parent = ann_i[0];
          ann_i[k]->m_edges.push_back(tmp);
          ann_i[k]->m_edgeWeight.push_back(0.5);
        }
      }
    }
    m_parent = m_parent->m_edges[0];
  }
}

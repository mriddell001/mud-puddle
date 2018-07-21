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

/**
 * ANN - This function serves as the constructor for the ANN object. It sets the
 *    four basic size values: input, hidden, output, hidden layers. It calls the
 *    init() function afterwards and checks that it executed sucessfully.
 *
 * Assumptions: This function assumes the int array argument contains four valid
 *    integer values to be set.
 *
 * Testing status: Untested.
 */
ANN::ANN(int in[4]) {
  m_input_size = in[0];
  m_hidden_layers = in[1];
  m_hidden_size = in[2];
  m_output_size = in[3];

  bool init_success = init();
  if(!init_success) {
    cout << "There has been a problem with the init function.\n";
  }
}

/**
 * ~ANN - This function serves as the deconstructor for the ANN object. It runs
 *    a for loop itterating through each vector (input/hidden/output) and calls
 *    to delete each Node pointer.
 *
 * Assumptions: This function assumes the delete function is called successfully
 *
 * Testing status: Untested.
 */
ANN::~ANN() {
  for (auto it = ann_i.begin(); it != ann_i.end(); ++it)
    delete *it;
  for (auto it = ann_h.begin(); it != ann_h.end(); ++it)
    delete *it;
  for (auto it = ann_o.begin(); it != ann_o.end(); ++it)
    delete *it;
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
  int a = m_input_size, b = m_hidden_size,
      c = m_output_size, d = m_hidden_layers;

  ///For each node in the input layer.
  for (int i = 0; i < a; i++) {
    tmp = new Node();
    ann_i.push_back(tmp);
  }

  //For each hidden layers.
  for (int i = 0; i < d; i++) {
    ///For each node in a hidden layer.
    for (int j = 0; j < b; j++) {
      tmp = new Node();
      ann_h.push_back(tmp);
      if (i) {
        int l = (i - 1) * b;
        ///For each node in a hidden layer.
        ///Add the newly created node to the vector of edges
        ///of the previous layer.
        for (int k = 0; k < b; k++) {
          pmt = ann_h[l+k];
          (*pmt).m_edges.push_back(tmp);
          (*pmt).m_edgeWeight.push_back(0.5);
        }
      }
      else {
        ///For each node in the input layer.
        ///Add the newly created node to the vector of edges.
        for (vector<Node*>::iterator it = ann_i.begin() ; it != ann_i.end(); ++it) {
          (*it)->m_edges.push_back(tmp);
          (*it)->m_edgeWeight.push_back(0.5);
        }
      }
    }
  }

  int l = (d*b)-b;
  ///For each node in the output layer.
  for (int i = 0; i < c; i++) {
    tmp = new Node();
    ann_o.push_back(tmp);
    ///For each node in the last hidden layer.
    for (int j = 0; j < b; j++) {
      pmt = ann_h[l+j];
      (*pmt).m_edges.push_back(tmp);
      (*pmt).m_edgeWeight.push_back(0.5);
    }
  }
  return true;
}

/**
 * testing_handler - This function serves as a centeral location to run batches
 *    of functions based on an instruction stream. This stream should include a
 *    set of instruction that:
 *    - Prime the Input Layer
 *    - Engage Network Calculations
 *    - Measure Euclidian Distance from Target Answer
 *    - Perform Backpropagation
 *
 *
 * Assumptions:
 *
 * Testing status: Untested.
 */
void ANN::testing_handler(istream &stream) {

}

/**
 * auto_refine - This function serves as an automatic refining of the ANN to
 *    reach a certain level of error consistantly. It randomly uses true
 *
 *
 *
 * Assumptions:
 *
 * Testing status: Untested.
 */
void ANN::auto_refine(istream &stream) {
  vector<test_case*> t_cases;
  double error_target;
  stream >> error_target;
  bool t;
  double v;
  while(stream >> t) {
    test_case *t_c;
    (*t_c).type = t;
    for (int i = 0; i < m_input_size; i++) {
      t_c->input.push_back(stream >> v);
    }
    for (int i = 0; i < m_output_size; i++) {
      t_c->output.push_back(stream >> v);
    }
  }

    test_case *tmp;
    stream >> t;

  }

}

/**
 * prime_input - This function serves to set the input layer to the values used
 *    by the current test investigated. This can be used to train the network or
 *    to use it in its finished form.
 *
 * Assumptions:
 *
 * Testing status: Untested.
 */
bool ANN::prime_input(istream &stream) {
  double tmp;
  for (vector<Node*>::iterator it = ann_i.begin() ; it != ann_i.end(); ++it) {
    stream >> tmp;
    (*it)->m_weight = tmp;
  }
  return true;
}

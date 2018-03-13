//Node.h
#ifndef NODE_H
#define NODE_H

#include <vector>

class Node {
public:
  Node(){
    m_weight = 0.5;
  };
  ~Node();

  std::vector<Node*> m_edges;       //Pointers to nodes in next layer.
  Node* m_parent;                   //Pointer to the start of the previous layer
  std::vector<double> m_edgeWeight; //Weights of paths to nodes in next layer.
  int m_layer;                      //Label of layer: 0-Input;1-Hidden;2-Output
  double m_weight;                  //Weight of node. Default: 0.5
};

#endif // Node_H

#ifndef VISITOR_HH
#define VISITOR_HH

#include "Node.h"
#include <iostream>

namespace lnk
{
  class Node;
  class FetchExpression;
}

class Visitor
{
public:
  virtual void visit(lnk::Node &node)
  {
    std::cout << "node";
  }

  virtual void visit(lnk::FetchExpression &expr)
  {
    std::cout << "fetch";
  }
};

#endif

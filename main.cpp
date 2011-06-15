#include "Node.h"
#include "Lexer.hh"
#include <iostream>
 

int main()
{
  Visitor visitor;
  lnk::FetchExpression expr;
  lnk::Node node;
  visitor.visit(expr);
  visitor.visit(node);
}

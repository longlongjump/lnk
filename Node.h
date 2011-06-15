#ifndef NODE_H
#define NODE_H
#include <tr1/memory>
#include <string>
#include "Visitor.hh"

namespace std{ using namespace tr1; }


namespace lnk
{

  
  class Node
  {
  public:
    Node(){}
    virtual ~Node(){}
    Node *parent;
    std::shared_ptr<Node> left,right;

    void accept(Visitor &visitor)
    {
      visitor.visit(*this);
    }
  };


  class FetchResult: public Node
  {
    int index;
  };

  class Expression : public Node
  {
  public:
    ~Expression(){}
  };

  class KeyResultNode: public Node
  {
    std::string key;
  };

  class IndexResultNode: public Node
  {
    size_t index;
  };

  class FetchNode: public Node
  {
  public:
    std::string name;
  };

  class FetchPath: public Node
  {
  };

  class FetchExpression: public Node
  {
  };


  class PredicateExpression:public Expression
  {
    
  };

  class SelectExpression: public Node
  {
  public:
    virtual void addPredicate(std::shared_ptr<Node> predicate){}
    virtual void addFetchResult(std::shared_ptr<Node> fetchResult){}
    virtual ~SelectExpression(){}
  };

  

}//namespace

#endif

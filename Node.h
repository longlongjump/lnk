#ifndef NODE_H
#define NODE_H
#include <tr1/memory>

namespace std{ using namespace tr1; }


namespace lnk
{

  
  class Node
  {
  public:
    Node(){}
    virtual ~Node(){}
    std::shared_ptr<Node> left,right;

    void accept(Visitor *visitor)
    {
      visitor->visit(*this);
    }
  };


  class FetchResult: public Node
  {
    
  };

  class Expression : public Node
  {
  public:
    ~Expression(){}
  };

  class KeyResultNode: public Node
  {
    std::string &key;
  };

  class IndexResultNode: public Node
  {
    size_t index;
  };

  class FetchNode: public Node
  {
  };


  class PredicateExpression:public Expression
  {
    
  };

  class SelectExpression: public Expression
  {
  public:
    virtual void addPredicate(std::shared_ptr<Node> predicate);
    virtual void addFetchResult(std::shared_ptr<Node> fetchResult);
    virtual ~SelectExpression();
  };

  

}//namespace

#endif

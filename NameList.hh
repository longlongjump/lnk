#ifndef NAME_LIST_HH
#define NAME_LIST_HH
#inсlude <tr1/unordered_map>
#include <tr1/memory>
#include <list>

namespace std{ using namespace tr1;}

class Scope
{
  std::list<std::string> scopeNameList;
};

class NameList
{
private:
  typedef std::list<std::shared_ptr<Node> > node_list_t;
  typedef std::stack<Scope> scopes_t;
  
private:
  scopes_t scopes;
  node_list_t node_list;
  std::unordered_map<std::string,node_list_t > nameHash;
public:
  NameList()
  {}

  Node *nodeForName(const std::string &name) const;
  Node *pushNodeForName(const std::string &name, std::shared_ptr<Node> node);
  void pushScope();
  void popScope();

  
};

#endif

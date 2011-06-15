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
  typedef std::unordered_map<std::string,node_list_t > name_hash_t;
  typedef std::list<std::shared_ptr<Node> > node_list_t;
  typedef std::stack<Scope> scopes_t;
  
private:
  scopes_t scopes;
  node_list_t node_list;
  name_hash_t names;
  
  Scope global_scope;

private:
  class Scope
  {
  public:
    node_list names;
  };
  
  
public:
  NameList()
  {
    
  }

  Node *nodeForName(const std::string &name) const
  {
    name_hash_t::itertor it = names.find(name);
    if (it!=names.end())
      {
	node_list list &list = it->second;
	if (!list.empty())
	  return list.begin()->get();
	return 0;
      }
    return 0;
  }

  Node *pushNodeForName(const std::string &name, std::shared_ptr<FetchNode> node)
  {
    node->name;
    
  }
  
  void pushScope()
  {
    //scopes.push();
  }
  
  void popScope()
  {
    
  }

  
};

#endif

#include "Node.h"
#include "Lexer.hh"
#include <iostream>

int main()
{
  std::string  s = "[name.name.name \"\".name]";
  Lexer lexer(s);

  Token tok;
  while(tok.tokenType != TokenTypeEOF)
    {
      lexer.getToken(tok);
      std::cout << tok << std::endl;
    }

}

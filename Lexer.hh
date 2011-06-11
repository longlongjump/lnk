#ifndef LEXER_H
#define LEXER_H

#include "Token.h"
#include <stack>
#include <string>
#include <map>

//namespace std { using namespace std::tr1;}


class Lexer
{

 private:
  std::stack<Token> tokens;
  std::string::const_iterator iter;
  std::string::const_iterator first;
  std::string::const_iterator end;

public:
  std::map<std::string,std::string> operators;

 private:
  Token tokenize();

 public:
  Lexer(const std::string&);
  void getToken(Token &token);
  

};


#endif //LEXER_H

#ifndef PARSER_HH
#define PARSER_HH

#include "Node.h"
#include "Token.h"
#include "Lexer.hh"



static void throw_if_not_equal(Token &tok, TokenType type)
{
  if (!tok.isKind(type))
    throw std::runtime_error();
}

static void throw_if_not_equal(Token &tok, TokenType type, const std::string &message)
{
  if (!tok.isKind(type))
    throw std::runtime_error(message);
}

static void throw_parse_error(const std::string &message)
{
  throw std::runtime_error(message);
}

class Parser
{
private:
  Token currentToken;
  Lexer lex;
public:
  Parser()
  {}


  void readListResult(lnk::SelectExpression &expr)
  {
    if (currentToken.isKind(TokenTypeName))
      {
	
      }
  }

  void readDictResult(lnk::SelectExpression &expr)
  {
    
  }

 

  void select(lnk::SelectExpression &expr)
  {
    if (currentToken.isKind(TokenTypeLRBrace))
      {
	ListResult *listResult = new ListResult;
	lex.getToken(currentToken);
	readListResult(expr);
	throw_if_not_equal(currentToken,TokenTypeRRBrace,
			   "missing ]");
       
      }
    else if(currentToken.isKind(TokenTypeRCBrace))
      {
	DictResult *dictResult = new DictResult;
	throw_if_not_equal(currentToken,TokenTypeRCBrace,
			   "missing }")

      }
    else
      {
	throw_parse_error("should start with [ or {");
      }

   
  }

  std::shared_ptr<lnk::Expression> parse(std::string & source)
  {
    lex = Lexer(source);
    lnk::SelectExpression expr = new SelectExpression();

    return expr;
  }

  
};


#endif

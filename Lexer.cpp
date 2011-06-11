#include "Lexer.hh"
#include <cstddef>
#include <iterator>
#include <stdexcept>


Lexer::Lexer(const std::string & source):
  iter(source.begin()),
  first(source.begin()),
  end(source.end())
{
}


void Lexer::getToken(Token &token)
{
  if (tokens.size() > 0)
    {
      token = tokens.top();
      tokens.pop();
    }
  else
    {
      token = tokenize();
    }
}


Token Lexer::tokenize()
{
  for(;iter!=end;)
    {
      char symbol = *iter;
      size_t location = std::distance(first,iter);
      switch(symbol)
	{
	case ' ':
	  ++iter;
	  break;
	case '+':
	  ++iter;
	  return Token(TokenTypePlus, location, 1);
	case '*':
	  ++iter;
	  return Token(TokenTypeStar, location, 1);
	case '(':
	  ++iter;
	  return Token(TokenTypeLBrace, location, 1);
	case ')':
	  ++iter;
	  return Token(TokenTypeRBrace, location, 1);
	case '[':
	  ++iter;
	  return Token(TokenTypeLRBrace, location, 1);
	case ']':
	  ++iter;
	  return Token(TokenTypeRRBrace, location, 1);
	case '.':
	  ++iter;
	  return Token(TokenTypeDot, location, 1);

	default:
	  {
	    if(::isdigit(symbol))
	      {
		for(;iter!=end && (::isdigit(*iter));++iter);
		size_t lenght = std::distance(first,iter);
		return Token(TokenTypeNum,location,lenght-location);
	      }
	    else if(::isalpha(symbol))
	      {
		
		for(;iter!=end && ( ::isalpha(*iter) || ::isdigit(*iter));++iter);
		size_t lenght = std::distance(first,iter);
		return Token(TokenTypeName,location,lenght-location);
	      }
	    else if(symbol=='\'' || symbol=='"')
	      {
		++iter;
		for(;iter!=end && ( ::isalpha(*iter) || ::isdigit(*iter));++iter);
		if (!(*iter=='\'' || *iter=='"') || iter==end)
		  throw std::runtime_error("Parse error: string missing quotion mark");
		++iter;
		size_t length = std::distance(first,iter);
		return Token(TokenTypeString,location+1,(length-location)-2);
	      }
	  }
	  
	  
	}
    }
  return Token(TokenTypeEOF, std::distance(first,end), 0);
}


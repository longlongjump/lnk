#ifndef TOKEN_H
#define TOKEN_H
#include <cstddef>
#include <ostream>

enum TokenType
  {
    TokenTypeNone = 0,
    TokenTypeString,
    TokenTypeName,
    TokenTypeOr,
    TokenTypePlus,
    TokenTypeStar,
    TokenTypeNum,
    TokenTypeDot,
    TokenTypeColon,
    TokenTypeLBrace, // (
    TokenTypeRBrace, // )
    TokenTypeLRBrace, // [
    TokenTypeRRBrace, // ]
    TokenTypeEOF

  };

static const char *tokenNames[] = 
  {
   "TokenTypeNone",
   "TokenTypeString",
   "TokenTypeName",
   "TokenTypeOr",
   "TokenTypePlus",
   "TokenTypeStar",
   "TokenTypeNum",
   "TokenTypeDot", 
   "TokenTypeColon",
   "TokenTypeLBrace",
   "TokenTypeRBrace",
   "TokenTypeLRBrace",
   "TokenTypeRRBrace",
   "TokenTypeEOF"
  };

struct Range
{
public:
  size_t location;
  size_t length;
public:
Range(size_t location,size_t length):location(location),length(length)
  {
  }
Range():location(0),length(0)
  {}
};


struct Token
{
  TokenType tokenType;
  Range range;
public:
Token(TokenType type, size_t position, size_t length):
  tokenType(type),range(position,length)
  {
  }
  
Token():
  tokenType(TokenTypeNone),range(0,0)
  {
  }

};


inline std::ostream &operator<<(std::ostream &os, Token &tok)
{
  os << tokenNames[tok.tokenType] << " location:" << tok.range.location << " length:" << tok.range.length;
  return os;
}

#endif

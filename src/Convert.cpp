#include "Convert.hpp"
#include <sstream>
#include <iomanip>
#include <cctype>
using namespace std;

string conv::byteToHex(uint8_t b){
  ostringstream oss; oss<<uppercase<<hex<<setw(2)<<setfill('0')<<(int)b;
  return oss.str();
}
string conv::byteToBin(uint8_t b){
  string s; s.reserve(8);
  for(int i=7;i>=0;--i) s.push_back( (b&(1<<i)) ? '1':'0' );
  return s;
}
char conv::byteToAscii(uint8_t b){
  return (b>=32 && b<127) ? static_cast<char>(b) : '.';
}
optional<uint8_t> conv::parseHexByte(const string& in){
  string s=in;
  if(s.size()>2 && s[0]=='0' && (s[1]=='x'||s[1]=='X')) s=s.substr(2);
  if(s.size()==1) s="0"+s;
  if(s.size()!=2) return nullopt;
  auto hexval=[](char c)->int{
    if(c>='0'&&c<='9') return c-'0';
    if(c>='a'&&c<='f') return 10+(c-'a');
    if(c>='A'&&c<='F') return 10+(c-'A');
    return -1;
  };
  int hi=hexval(s[0]), lo=hexval(s[1]);
  if(hi<0||lo<0) return nullopt;
  return static_cast<uint8_t>((hi<<4)|lo);
}

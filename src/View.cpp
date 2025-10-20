#include "View.hpp"
#include "Convert.hpp"
#include <sstream>
#include <iomanip>
using namespace std;

string view::renderPage(const vector<uint8_t>& buf, size_t offset, size_t pageSize, size_t bpl){
  ostringstream out;
  size_t end = (offset + pageSize > buf.size()) ? buf.size() : offset + pageSize;

  out << "OFFSET  | HEX ("<< bpl <<" B/line)                           | BIN (8b)                           | ASCII\n";
  out << "---------------------------------------------------------------------------------------------\n";

  for(size_t base = offset; base < end; base += bpl){
    out<<uppercase<<hex<<setw(8)<<setfill('0')<<base<<dec<<" | ";
    for(size_t i=0;i<bpl;i++){
      size_t idx = base+i;
      if(idx<end) out<<conv::byteToHex(buf[idx])<<' ';
      else out<<"   ";
    }
    out<<"| ";
    for(size_t i=0;i<bpl;i++){
      size_t idx = base+i;
      if(idx<end) out<<conv::byteToBin(buf[idx])<<' ';
      else out<<"         ";
    }
    out<<"| ";
    for(size_t i=0;i<bpl;i++){
      size_t idx = base+i;
      if(idx<end) out<<conv::byteToAscii(buf[idx]);
      else out<<' ';
    }
    out<<'\n';
  }
  return out.str();
}

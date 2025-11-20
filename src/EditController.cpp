/// \file EditController.cpp
/// \brief Implementierung der zentralen Steuerlogik (open/view/editHex/save).
#include "EditController.hpp"
#include "FileIO.hpp"
#include "View.hpp"
#include "Convert.hpp"
#include <stdexcept>
using namespace std;

bool EditController::open(const string& path){
  try{
    buffer = io::loadFile(path);
    filePath = path;
    return true;
  }catch(const exception&){
    return false;
  }
}
string EditController::view(size_t offset) const{
  if(buffer.empty()) return "No file loaded.\n";
  if(offset >= buffer.size()) offset = buffer.size() - (buffer.size()%256);
  return ::view::renderPage(buffer, offset);
}
bool EditController::editHex(size_t offset, const string& hexByte){
  if(offset >= buffer.size()) return false;
  auto val = conv::parseHexByte(hexByte);
  if(!val) return false;
  buffer[offset] = *val;
  return true;
}
bool EditController::save(const string& outPath) const{
  if(buffer.empty()) return false;
  string path = outPath.empty() ? filePath : outPath;
  if(path.empty()) return false;
  try{
    io::saveFile(path, buffer);
    return true;
  }catch(const exception&){
    return false;
  }
}

/// \file FileIO.cpp
/// \brief Implementierung der Funktionen zum Laden und Speichern von Binärdateien.
#include "FileIO.hpp"
#include <fstream>
#include <stdexcept>

using namespace std;

vector<uint8_t> io::loadFile(const string& path) {
  ifstream ifs(path, ios::binary);
  if(!ifs) throw runtime_error("cannot open file: " + path);
  vector<uint8_t> data((istreambuf_iterator<char>(ifs)), {});
  return data;
}

void io::saveFile(const string& path, const vector<uint8_t>& data) {
  ofstream ofs(path, ios::binary | ios::trunc);
  if(!ofs) throw runtime_error("cannot open for write: " + path);
  ofs.write(reinterpret_cast<const char*>(data.data()), static_cast<streamsize>(data.size()));
}

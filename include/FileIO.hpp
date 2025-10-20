#pragma once
#include <string>
#include <vector>
#include <cstdint>

namespace io {
  std::vector<uint8_t> loadFile(const std::string& path);
  void saveFile(const std::string& path, const std::vector<uint8_t>& data);
}

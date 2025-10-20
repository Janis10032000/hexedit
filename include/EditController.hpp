#pragma once
#include <vector>
#include <string>
#include <cstdint>
#include <cstddef>

class EditController {
public:
  bool open(const std::string& path);
  std::string view(size_t offset) const;
  bool editHex(size_t offset, const std::string& hexByte);
  bool save(const std::string& outPath="") const;
private:
  std::vector<uint8_t> buffer;
  std::string filePath;
};

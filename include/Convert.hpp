#pragma once
#include <string>
#include <cstdint>
#include <optional>

namespace conv {
  std::string byteToHex(uint8_t b);
  std::string byteToBin(uint8_t b);
  char byteToAscii(uint8_t b);
  std::optional<uint8_t> parseHexByte(const std::string& s);
}

/// \file Convert.hpp
/// \brief Funktionen zur Umwandlung von Bytes in HEX-, BIN- und ASCII-Darstellung.
#pragma once
#include <string>
#include <cstdint>
#include <optional>

namespace conv {
/// \brief Wandelt ein Byte in einen 2-stelligen HEX-String.
  std::string byteToHex(uint8_t b);
/// \brief Wandelt ein Byte in einen 2-stelligen HEX-String.
  std::string byteToBin(uint8_t b);
/// \brief Wandelt ein Byte in einen 2-stelligen HEX-String.
  char byteToAscii(uint8_t b);
/// \brief Wandelt ein Byte in einen 2-stelligen HEX-String.
  std::optional<uint8_t> parseHexByte(const std::string& s);
/// \brief Wandelt ein Byte in einen 2-stelligen HEX-String.
}

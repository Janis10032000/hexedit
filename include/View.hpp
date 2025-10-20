#pragma once
#include <vector>
#include <cstdint>
#include <cstddef>
#include <string>

namespace view {
  std::string renderPage(const std::vector<uint8_t>& buf, size_t offset, size_t pageSize=256, size_t bytesPerLine=16);
}

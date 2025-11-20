/// \file View.hpp
/// \brief Darstellung eines Bytepuffers (HEX/BIN/ASCII) im Terminal.
#pragma once
#include <vector>
#include <cstdint>
#include <cstddef>
#include <string>

namespace view {
/// \brief Rendert eine formatierte Seite des Bytepuffers.
/// \param buf Bytepuffer.
/// \param offset Startoffset.
/// \param pageSize Bytes pro Seite.
/// \param bytesPerLine Bytes pro Zeile.
/// \return Formatierter Ausgabestring.
  std::string renderPage(const std::vector<uint8_t>& buf, size_t offset, size_t pageSize=256, size_t bytesPerLine=16);
}

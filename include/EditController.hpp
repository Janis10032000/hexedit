/// \file EditController.hpp
/// \brief Kontrolliert Dateioperationen, Ansicht und Bearbeitung.
#pragma once
#include <vector>
#include <string>
#include <cstdint>
#include <cstddef>

class EditController {
public:
/// \brief Lädt eine Datei in den internen Puffer.
/// \return true wenn erfolgreich.
  bool open(const std::string& path);
/// \brief Gibt eine formatierte Seitenansicht zurück.
  std::string view(size_t offset) const;
/// \brief Bearbeitet ein Byte an einer Offset-Position in HEX-Notation.
/// \return true wenn gültig.
  bool editHex(size_t offset, const std::string& hexByte);
/// \brief Speichert den Puffer in eine Datei.
/// \return true wenn erfolgreich.
  bool save(const std::string& outPath="") const;
private:
  std::vector<uint8_t> buffer;
  std::string filePath;
};

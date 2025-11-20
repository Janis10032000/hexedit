/// \file FileIO.hpp
/// \brief Laden und Speichern von Binärdateien.
/// \details Enthält Funktionen, um Dateien vollständig in einen Bytepuffer zu laden
///          und Änderungen wieder auf die Festplatte zu schreiben.
#pragma once
#include <string>
#include <vector>
#include <cstdint>

namespace io {
/// \brief Lädt eine Datei vollständig in einen Bytepuffer.
/// \param path Pfad der Datei.
/// \return Bytepuffer.
/// \throws std::runtime_error Bei Lese- oder Zugriffsfehlern.
  std::vector<uint8_t> loadFile(const std::string& path);
/// \brief Speichert den Bytepuffer in eine Datei.
/// \param path Zieldatei.
/// \param data Bytepuffer.
/// \throws std::runtime_error Bei Schreibfehlern.
  void saveFile(const std::string& path, const std::vector<uint8_t>& data);
}

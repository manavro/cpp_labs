#ifndef SEARCH_H
#define SEARCH_H

#include <filesystem>
#include <string>
#include <vector>


namespace fs = std::filesystem;


std::vector<fs::path> search_files_by_name(const fs::path& directory, const std::string& filename);

std::vector<fs::path> search_files_by_content(const fs::path& directory, const std::string& search_term);

#endif // SEARCH_H
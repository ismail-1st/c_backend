#include "env.h"
#include "../functions/functions.h"
#include <fstream>
#include <algorithm>
#include <cstdlib>

#ifdef _WIN32   
#include <windows.h>
#endif

Env::Env(const std::string& path) {
    if(!path.empty()) load(path); 
}

bool Env::load(const std::string& path) {
    variables.clear();

    std::ifstream file(path);
    if (!file.is_open()) return false;

    std::string line;
    while(std::getline(file, line)) {
        // remove the whitespaces
        line = remove_whitespaces(line);

        if(line.empty() || line[0] == '#') continue;

        auto pos = line.find('=');
        if(pos == std::string::npos) continue;

        std::string key = line.substr(0, pos);
        std::string value = line.substr(pos + 1);

        variables[key] = value;
    }

    return true;
}

void Env::exportToSystem() const {
    for(const auto& [key, value]: variables) {
#ifdef _WIN32
            _putenv_s(key.c_str(), value.c_str());
#else
            setenv(key.c_str(), value.c_str(), 1);
#endif
    }
}

std::string Env::get(const std::string& key, const std::string& default_value) const {
    auto it = variables.find(key);
    return it != variables.end() ? it->second : default_value;
}
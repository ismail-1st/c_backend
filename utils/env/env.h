#pragma once
#include <string>
#include <map>

class Env {
public:
    // the constructor can auto load a file
    explicit Env(const std::string& path = "");

    // load or reload the .env file
    bool load(const std::string& path);

    // export
    void exportToSystem() const;

    // get a specific env var
    std::string get(const std::string& key, const std::string& default_value = "") const;

private:
    std::map<std::string, std::string> variables;
};
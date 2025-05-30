#include "db.h"
#include <cstdlib>
#include <iostream>

DB::DB(): conn(nullptr) {}

DB::~DB() {
    disconnect();
}

std::string DB::buildConnectionString() const {
    const char* host = std::getenv("DB_HOST");
    const char* port = std::getenv("DB_PORT");
    const char* user = std::getenv("DB_USER");
    const char* password = std::getenv("DB_PASSWORD");
    const char* db_name = std::getenv("DB_NAME");

    return  "host=" + std::string(host ? host : "")+
        "port=" + std::string(port ? port : "")+
        "user=" + std::string(user ? user : "")+
        "password=" + std::string(password ? password : "")+
        "db_name=" + std::string(db_name ? db_name : "")+
        "sslmode=require";
}

bool DB::connect() {
    try {
        conn = new pqxx::connection(buildConnectionString());
        if (conn->is_open()) {
            std::cout << "Connected to NeonDB.\n";
            return true;
        } else {
            std::cerr << "Connection failed.\n";
            return false;
        }
    } catch (const std::exception& e) {
        std::cerr << "Connection Error: " << e.what() << "\n";
        return false;
    }
}

void DB::disconnect() {
    if (conn) {
        conn->disconnect();
        delete conn;
        conn = nullptr;
        std::cout << "Disconnected successfully.\n";
    }
}

bool DB::isConnected() const {
    return conn && conn->is_open();
}
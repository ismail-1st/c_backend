#ifndef DB_CONNECTION_H
#define DB_CONNECTION_H

#include <pqxx/pqxx>
#include <string>

class DB {
public:
    DB();
    ~DB();

    bool connect();
    void disconnect();
    bool isConnected() const;

private:
    std::string buildConnectionString() const;
    pqxx::connection* conn;

};

#endif
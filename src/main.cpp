#include <iostream>
#include "../utils/env/env.h"
#include "../db/db.h"

int main() {

    Env env;
    if(env.load("./.env")) {
        env.exportToSystem();
        std::cout << "FIRST ENV: " << env.get("DB_HOST") << std::endl;

        DB db;
        if(db.connect()) {
            std::cout << "Db loaded. " << std::endl;
        }

    } else {
        std::cerr << "Failed to load .env file \n";
    }

    return 0;
}
#include <iostream>
#include "../utils/env/env.h"

int main() {

    Env env;
    if(env.load("../.env/.env")) {
        env.exportToSystem();

        std::cout << "FIRST ENV: " << env.get("IDK") << endl;
    } else {
        std::cerr << "Failed to load .env file \n";
    }

    return 0;
}
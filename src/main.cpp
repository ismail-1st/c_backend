#include <iostream>
#include "../utils/env/env.h"

int main() {

    Env env;
    if(env.load("./.env")) {
        env.exportToSystem();

        std::cout << "FIRST ENV: " << env.get("IDK") << std::endl;
    } else {
        std::cerr << "Failed to load .env file \n";
    }

    return 0;
}
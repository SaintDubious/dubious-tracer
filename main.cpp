#include <iostream>

int main(int argc, char** argv )
{
    try {
        std::cout << "Start\n";
        std::cout << "End\n";
        return 0;
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << "\n";
    }
    catch (...) {
        std::cout << "Exception\n";
    }
    return 1;
}
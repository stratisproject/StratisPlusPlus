#include "StratisDemo.h"

int main(int argc, char** argv)
{
    stratis::StratisDemo stratisDemo;

    try {
        stratisDemo.runDemo();
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return 1;
    }

    return 0;
}
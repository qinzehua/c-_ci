#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <thread>
#if defined(_WIN32)
#include <windows.h>
#endif

int main() {
#if defined(_WIN32)
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
    std::cout << "简易时钟 - 按 Ctrl+C 退出\n";

    while (true) {
        const auto now = std::chrono::system_clock::now();
        const std::time_t t = std::chrono::system_clock::to_time_t(now);
        const std::tm* const p = std::localtime(&t);
        if (!p) {
            std::cerr << "localtime failed\n";
            return 1;
        }
        std::tm local = *p;
        std::ostringstream oss;
        oss << std::put_time(&local, "%Y-%m-%d %H:%M:%S");
        std::cout << '\r' << oss.str() << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

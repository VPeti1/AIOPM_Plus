#include <chrono>
#include <cstdlib>
#include <iostream>
#include <string>
#include <thread>
#include <fstream>
#include <stdio.h>
#include <unistd.h>
#define clear std::cout << "\033[2J\033[1;1H";
using namespace std;




void dw() {
    std::string input;
    std::cout << "What distro are you using?" << std::endl;
    std::cout << "(arch,debian,fedora,opensuse or void)" << std::endl;
    std::cout << "(Derivatives included)" << std::endl;
    //derivatives like ubuntu,mint...
    std::cin >> input;
    if (input == "arch" || input == "Arch") {
        system("sudo pacman -S git wget gcc");
        std::cout << "Setting configuration for Arch" << std::endl;
        system("sudo touch /usr/aiopm/a1.cw");
    }
    else if (input == "debian" || input == "Debian") {
        system("sudo apt-get install git wget build-essential");
        std::cout << "Setting configuration for Debian" << std::endl;
        system("sudo touch /usr/aiopm/a2.cw");
    }
    else if (input == "fedora" || input == "Fedora") {
        system("sudo dnf install git wget gcc-c++");
        std::cout << "Setting configuration for Fedora" << std::endl;
        system("sudo touch /usr/aiopm/a3.cw");
    }
    else if (input == "opensuse" || input == "Opensuse") {
        system("sudo zypper install git wget gcc-c++");
        std::cout << "Setting configuration for Opensuse" << std::endl;
        system("sudo touch /usr/aiopm/a4.cw");
    }
    else if (input == "void" || input == "Void") {
        system("sudo xbps-install git wget gcc");
        std::cout << "Setting configuration for Void linux" << std::endl;
        system("sudo touch /usr/aiopm/a5.cw");
    }
    else {
        std::cout << "Invalid input\n";
        dw();
    }
    
}


int main() {
    system("sudo rm -rf /usr/aiopmi");
    system("sudo rm -rf /usr/aiopm");
    clear;
    std::cout << "AIOPM Plus Installer" << std::endl;
    std::cout << "By VPeti" << std::endl;
    sleep(2);
    system("sudo mkdir /usr/aiopm");
    system("sudo mkdir /usr/aiopmi");
    dw();
    system("read -p 'Press Enter to continue...'");
    system("sudo wget https://raw.githubusercontent.com/VPeti1/AIOPM_Plus/main/main.cpp -O /usr/aiopmi/pm.cpp");
    //Compiles with blast processing technology :)
    system("sudo g++ /usr/aiopmi/pm.cpp -o /bin/pm");
    system("sudo chmod +x /bin/pm");
    std::cout << "AIOPM Plus Installer Completed!" << std::endl;
    system("exit");
}
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
    std::string distro;
    std::cout << "Enter your Linux distribution (arch/debian/fedora/suse/void): ";
    std::cin >> distro;
    if (distro == "arch") {
        system("sudo pacman -S git wget gcc");
        system("sudo wget https://raw.githubusercontent.com/VPeti1/AIOPM_Plus/main/arch.cpp -O /usr/aiopmi/pm.cpp");
    }
    else if (distro == "debian") {
        system("sudo apt-get install git wget build-essential");
        system("sudo wget https://raw.githubusercontent.com/VPeti1/AIOPM_Plus/main/debian.cpp -O /usr/aiopmi/pm.cpp");
    }
    else if (distro == "fedora") {
        system("sudo dnf install git wget gcc-c++");
        system("sudo wget https://raw.githubusercontent.com/VPeti1/AIOPM_Plus/main/fedora.cpp -O /usr/aiopmi/pm.cpp");
    }
    else if (distro == "suse") {
        system("sudo zypper install git wget gcc-c++");
        system("sudo wget https://raw.githubusercontent.com/VPeti1/AIOPM_Plus/main/suse.cpp -O /usr/aiopmi/pm.cpp");
    }
    else if (distro == "void") {
        system("sudo xbps-install git wget gcc");
        system("sudo wget https://raw.githubusercontent.com/VPeti1/AIOPM_Plus/main/void.cpp -O /usr/aiopmi/pm.cpp");
    }
     else {
        std::cout << "Unsupported distribution. Please choose arch, debian, void, suse or fedora." << std::endl;
    }
}

int main() {
    system("sudo rm -rf /usr/aiopmi");
    clear;
    std::cout << "AIOPM Plus Installer" << std::endl;
    std::cout << "By VPeti" << std::endl;
    sleep(2);
    system("sudo mkdir /usr/aiopmi");
    dw();
    system("read -p 'Press Enter to continue...'");
    //Compiles with blast processing technology :)
    system("sudo g++ /usr/aiopmi/pm.cpp -o /bin/pm");
    system("sudo chmod +x /bin/pm");
    std::cout << "AIOPM Plus Installer Completed!" << std::endl;
    system("exit");
}
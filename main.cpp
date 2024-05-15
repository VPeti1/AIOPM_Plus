#include <iostream>
#include <cstdlib>
#include <cstring>
#include <stdexcept>
#include <unistd.h>
#include <fstream>
#include <sys/stat.h>
#define clear std::cout << "\033[2J\033[1;1H";
using namespace std;

string checkpm(string& name) {
    string path = "/etc/bin/" + name;
    struct stat buffer; 
    int result = (stat(path.c_str(), &buffer) == 0 ? 0 : 1);
    return std::to_string(result);
}

void fst() {
    clear
    //fst means first time setup
    std::cout << "Welcome to AIOPM Plus Setup! " << std::endl;
    std::string input;
    std::cout << "What distro are you using?" << std::endl;
    std::cout << "(arch,debian,fedora,opensuse or void)" << std::endl;
    std::cout << "(Derivatives included)" << std::endl;
    //derivatives like ubuntu,mint...
    std::cin >> input;
    if (input == "arch" || input == "Arch") {
        std::cout << "Setting configuration for Arch" << std::endl;
        system("sudo mkdir /etc/aiopm");
        system("sudo touch /etc/aiopm/a1.cw");
        //creates files for arch
    }
    else if (input == "debian" || input == "Debian") {
        std::cout << "Setting configuration for Debian" << std::endl;
        system("sudo mkdir /etc/aiopm");
        system("sudo touch /etc/aiopm/a2.cw");
    }
    else if (input == "fedora" || input == "Fedora") {
        std::cout << "Setting configuration for Fedora" << std::endl;
        system("sudo mkdir /etc/aiopm");
        system("sudo touch /etc/aiopm/a3.cw");
        //creates files for fedora
    }
    else if (input == "opensuse" || input == "Opensuse") {
        system("sudo mkdir /etc/aiopm");
        system("sudo touch /etc/aiopm/a4.cw");
    }
    else if (input == "void" || input == "Void") {
        system("sudo mkdir /etc/aiopm");
        system("sudo touch /etc/aiopm/a5.cw");
    }
    else{
        std::cout << "Invalid input! Retrying" << std::endl;
        system("read -p 'Press Enter to continue...'");
        fst();
    }
    
}

int main(int argc, char* argv[]) {
    //Splash screen
    std::cout << " $$$$$$\\  $$$$$$\\  $$$$$$\\  $$$$$$$\\  $$\\      $$\\ \n"
                 "$$  __$$\\ \\_$$  _|$$  __$$\\ $$  __$$\\ $$$\\    $$$ |\n"
                 "$$ /  $$ |  $$ |  $$ /  $$ |$$ |  $$ |$$$$\\  $$$$ |\n"
                 "$$$$$$$$ |  $$ |  $$ |  $$ |$$$$$$$  |$$\\$$\\$$ $$ |\n"
                 "$$  __$$ |  $$ |  $$ |  $$ |$$  ____/ $$ \\$$$  $$ |\n"
                 "$$ |  $$ |  $$ |  $$ |  $$ |$$ |      $$ |\\$  /$$ |\n"
                 "$$ |  $$ |$$$$$$\\  $$$$$$  |$$ |      $$ | \\_/ $$ |\n"
                 "\\__|  \\__|\\______| \\______/ \\__|      \\__|     \\__|\n";
    std::cout << "By VPeti" << std::endl;
    sleep(1);
    if (argc < 2) {
        std::cerr << "Too few arguments! Usage: pm <package_manager> <action> <package_name>\n";
        return 1;
    }

    if (argc < 3) {
        std::cerr << "Insufficient arguments! Usage: pm <package_manager> <action> <package_name>\n";
        return 1;
    }

    std::string packageManager = argv[1];
    std::string action = argv[2];

    if (packageManager != "sys") {
        if (packageManager != "aur") {
            string check = checkpm(packageManager);
            if (check == "1") {
                std::cout << "You dont have that package mananger installed";
                return 1;
            }
        }
    }    

    // Handle different package managers
    if (packageManager == "pip") {
        // Example pip commands
        if (action == "install") {
            std::string package = argv[3];
            std::cout << "Installing pip package: " << package << std::endl;
            system(("pip install " + package).c_str());
        } else if (action == "remove") {
            std::string package = argv[3];
            std::cout << "Removing pip package: " << package << std::endl;
            system(("pip uninstall " + package).c_str());
        } else if (action == "update") {
            std::string package = argv[3];
            std::cout << "Updating pip package: " << package << std::endl;
            system(("pip install --upgrade " + package).c_str());
        }
        else{
            std::cerr << "Invalid argument!\n";
        }
    } else if (packageManager == "flatpak") {
        // Example Flatpak commands
        if (action == "install") {
            std::string package = argv[3];
            std::cout << "Installing Flatpak package: " << package << std::endl;
            system(("flatpak install " + package).c_str());
        } else if (action == "remove") {
            std::string package = argv[3];
            std::cout << "Removing Flatpak package: " << package << std::endl;
            system(("flatpak uninstall " + package).c_str());
        }
        else if (action == "update") {
            std::cout << "Updating flatpak packages" << std::endl;
            system("flatpak update");
        }
        else{
            std::cerr << "Invalid argument!\n";
        }
    } else if (packageManager == "snap") {
        std::string package = argv[3];
        // Example Snap commands
        if (action == "install") {
            std::cout << "Installing Snap package: " << package << std::endl;
            system(("snap install " + package).c_str());
        } else if (action == "remove") {
            std::cout << "Removing Snap package: " << package << std::endl;
            system(("snap remove " + package).c_str());
        }
        else{
            std::cerr << "Invalid argument!\n";
        }
    } else if (packageManager == "sys") {
    std::ifstream file("/etc/aiopm/a1.cw");
    //arch file
    if (file.is_open()) {
        file.close();
                std::string package = argv[3];
        if (action == "install") {
        if (package.empty()) {
        cerr << "Error: No package names specified. Please provide at least one package name.\n";
        return 1;
        }
        system(("sudo pacman -S " + package).c_str());
    } else if (action == "remove") {
        if (package.empty()) {
        cerr << "Error: No package names specified. Please provide at least one package name.\n";
        return 1;
        }
        system(("sudo pacman -Rs " + package).c_str());
    } else if (action == "update") {
        if (argc >= 3) {
            std::cout << "Too many arguments\n";
            return 1;
        } else {
            system("sudo pacman -Syy");
        }
    } else if (action == "upgrade") {
        if (argc >= 3) {
            std::cout << "Too many arguments\n";
            return 1;
        } else {
            system("sudo pacman -Su");
        }
    } else if (action == "upd") {
        if (argc >= 3) {
            std::cout << "Too many arguments\n";
            return 1;
        } else {
            system("sudo pacman -Syu");
        }
    }
    else if (action == "show") {
        if (package.empty()) {
        cerr << "Error: No package names specified. Please provide at least one package name.\n";
        return 1;
        }
        system(("sudo pacman -Q " + package).c_str());
    } else if (action == "localinstall") {
        if (package.empty()) {
        cerr << "Error: No package path specified. Please provide a package path.\n";
        return 1;
        }
        if (argc > 3) {
        std::cout << "Too many arguments!" << std::endl;
        }
        system(("sudo pacman -U " + package).c_str());
    } else if (action == "list") {
        if (package.empty()) {
        cerr << "Error: No package names specified. Please provide at least one package name.\n";
        return 1;
        }
        system("sudo pacman -Q");
    } else if (action == "search") {
        if (package.empty()) {
        cerr << "Error: No package names specified. Please provide at least one package name.\n";
        return 1;
        }
        system(("sudo pacman -Si " + package).c_str());
    } else if (action == "mremove") {
        if (package.empty()) {
        cerr << "Error: No package names specified. Please provide at least one package name.\n";
        return 1;
        }
        system(("sudo pacman -R $(pacman -Qq | grep " + package + ")").c_str());
    }
     else {
        cerr << "Invalid argument!\n";
        return 1;
    }

    } else {
    //debian file
    std::ifstream file("/etc/aiopm/a2.cw");
    if (file.is_open()) {
        file.close();
                if (action == "install") {
            std::string package = argv[3];
            std::cout << "Installing APT package: " << package << std::endl;
            system(("sudo apt install " + package).c_str());
        } else if (action == "remove") {
            std::string package = argv[3];
            std::cout << "Removing APT package: " << package << std::endl;
            system(("sudo apt remove " + package).c_str());
        } else if (action == "update") {
            std::cout << "Updating APT packages" << std::endl;
            system("sudo apt update");
            system("sudo apt upgrade");
        }
        else{
            std::cerr << "Invalid argument!\n";
        }

    }
    else {
        //fedora file
        std::ifstream file("/etc/aiopm/a3.cw");
    if (file.is_open()) {
        file.close();
                if (action == "install") {
            std::string package = argv[3];
            std::cout << "Installing APT package: " << package << std::endl;
            system(("sudo apt install " + package).c_str());
        } else if (action == "remove") {
            std::string package = argv[3];
            std::cout << "Removing APT package: " << package << std::endl;
            system(("sudo apt remove " + package).c_str());
        } else if (action == "update") {
            std::cout << "Updating APT packages" << std::endl;
            system("sudo apt update");
            system("sudo apt upgrade");
        }
        else{
            std::cerr << "Invalid argument!\n";
        }

    }
    else {
    //opensuse file
    std::ifstream file("/etc/aiopm/a4.cw");
    if (file.is_open()) {
        file.close();
                if (action == "install") {
            std::string package = argv[3];
            std::cout << "Installing zypper package: " << package << std::endl;
            system(("sudo zypper install " + package).c_str());
        } else if (action == "remove") {
            std::string package = argv[3];
            std::cout << "Removing zypper package: " << package << std::endl;
            system(("sudo zypper remove " + package).c_str());
        } else if (action == "update") {
            std::cout << "Updating zypper packages" << std::endl;
            system("sudo zypper update");
        }
        else{
            std::cerr << "Invalid argument!\n";
        }

    }
    else {
    //void file
    std::ifstream file("/etc/aiopm/a5.cw");
    if (file.is_open()) {
        file.close();
                if (action == "install") {
            std::string package = argv[3];
            std::cout << "Installing XBPS package: " << package << std::endl;
            system(("sudo xbps-install " + package).c_str());
        } else if (action == "remove") {
            std::string package = argv[3];
            std::cout << "Removing XBPS package: " << package << std::endl;
            system(("sudo xbps-remove " + package).c_str());
        } else if (action == "update") {
            std::cout << "Updating XBPS packages" << std::endl;
            system("sudo xbps-install -Su");
        }
        else{
            std::cerr << "Invalid argument!\n";
        }

    }
    else {
        fst();
    }
    }
    }
    }
    }
    }
     else if (packageManager == "aur") {
        std::ifstream file("/etc/bin/yay");
        if (file.is_open()) {
            if (action == "install") {
                std::string package = argv[3];
            if (package.empty()) {
                cerr << "Error: No package names specified. Please provide at least one package name.\n";
                return 1;
            }
        system(("yay -S " + package).c_str());
    }
    }
    else {
        cerr << "Error: Your dont have yay installed!!.\n";
        return 1;
        }
     }
    else {
        std::cerr << "Invalid package manager.\n";
        return 1;
    }
}

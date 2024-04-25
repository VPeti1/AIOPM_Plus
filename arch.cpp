#include <iostream>
#include <cstdlib>
#include <cstring>
#include <stdexcept>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Too few arguments! Usage: pm <package_manager> <action> <package_name>\n";
        
    }

    std::string packageManager = argv[1];

    if (argc < 3) {
        std::cerr << "Insufficient arguments! Usage: pm <package_manager> <action> <package_name>\n";
        
    }

    std::string action = argv[2];
    

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
        std::string package = argv[3];
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
            std::cout << "Updating flatpak package: " << package << std::endl;
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
    }
    else {
        std::cerr << "Invalid package manager.\n";
    }
}

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <stdexcept>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Too few arguments! Usage: pm <package_manager> <action> <package_name>\n";
        
    }

    std::string packageManager = argv[1];

    if (argc < 4) {
        std::cerr << "Insufficient arguments! Usage: pm <package_manager> <action> <package_name>\n";
        
    }

    std::string action = argv[2];
    std::string package = argv[3];

    // Handle different package managers
    if (packageManager == "pip") {
        // Example pip commands
        if (action == "install") {
            std::cout << "Installing pip package: " << package << std::endl;
            system(("pip install " + package).c_str());
        } else if (action == "remove") {
            std::cout << "Removing pip package: " << package << std::endl;
            system(("pip uninstall " + package).c_str());
        } else if (action == "update") {
            std::cout << "Updating pip package: " << package << std::endl;
            system(("pip install --upgrade " + package).c_str());
        }
    } else if (packageManager == "flatpak") {
        // Example Flatpak commands
        if (action == "install") {
            std::cout << "Installing Flatpak package: " << package << std::endl;
            system(("flatpak install " + package).c_str());
        } else if (action == "remove") {
            std::cout << "Removing Flatpak package: " << package << std::endl;
            system(("flatpak uninstall " + package).c_str());
        }
    } else if (packageManager == "snap") {
        // Example Snap commands
        if (action == "install") {
            std::cout << "Installing Snap package: " << package << std::endl;
            system(("snap install " + package).c_str());
        } else if (action == "remove") {
            std::cout << "Removing Snap package: " << package << std::endl;
            system(("snap remove " + package).c_str());
        }
    } else if (packageManager == "deb") {
        // Example Debian commands
        if (action == "install") {
            std::cout << "Installing APT package: " << package << std::endl;
            system(("sudo apt install " + package).c_str());
        } else if (action == "remove") {
            std::cout << "Removing APT package: " << package << std::endl;
            system(("sudo apt remove " + package).c_str());
        } else if (action == "update") {
            std::cout << "Updating APT packages" << std::endl;
            system("sudo apt update");
            system("sudo apt upgrade");
        }
    } else {
        std::cerr << "Invalid package manager. Use 'pip', 'flatpak', 'snap', or 'deb'.\n";
    }
}

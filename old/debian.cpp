#include <iostream>
#include <cstdlib>
#include <cstring>
#include <stdexcept>

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
            std::cout << "Updating flatpak packages: " << package << std::endl;
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
        // Example Debian commands
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
    else if (packageManager == "flex") {

        if (action == "install") {
            std::string package = argv[3];
            system("sudo mkdir /usr/flexpkgr/");
            system(("wget https://raw.githubusercontent.com/VPeti1/FlexPackages/main/" + package + " /flex.pkg -O flex.pkg").c_str());
            system("flex");
        }
        if (action == "init") {
            system("wget https://github.com/VPeti1/FlexPkg/raw/master/installer.out -O installer.out");
            system("sudo chmod +x installer.out");
            system("./installer.out");
        }
        else{
            std::cerr << "Invalid argument!\n";
        }
    }
    else {
        std::cerr << "Invalid package manager. Use 'pip', 'flatpak', 'snap', or 'deb'.\n";
    }
}

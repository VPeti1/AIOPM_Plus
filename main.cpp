#include <iostream>
#include <cstdlib>
#include <cstring>
#include <stdexcept>
#include <unistd.h>
#include <fstream>
#define clear std::cout << "\033[2J\033[1;1H";
using namespace std;

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
    std::ifstream file("/usr/aiopm/a1.cw");
    //arch file
    if (file.is_open()) {
        file.close();
        if (action == "install") {
            std::string package = argv[3];
            std::cout << "Installing pacman package: " << package << std::endl;
            system(("sudo pacman -S " + package).c_str());
        } else if (action == "remove") {
            std::string package = argv[3];
            std::cout << "Removing pacman package: " << package << std::endl;
            system(("sudo pacman -Rs " + package).c_str());
        } else if (action == "update") {
            std::cout << "Updating pacman packages" << std::endl;
            system("sudo pacman -Syu");
        }
        else if (action == "mremove") {
            std::string package = argv[3];
            std::cout << "Removing pacman packages" << std::endl;
            system((" sudo pacman -R $(pacman -Qq | grep " + package + ")").c_str());
        }
        else{
            std::cerr << "Invalid argument!\n";
        }

    } else {
    //debian file
    std::ifstream file("/usr/aiopm/a2.cw");
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
        std::ifstream file("/usr/aiopm/a3.cw");
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
    std::ifstream file("/usr/aiopm/a4.cw");
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
    std::ifstream file("/usr/aiopm/a5.cw");
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
        std::cout << "No sys file found!";
    }
    }
    }
    }
    }
    }
    else if (packageManager == "aur") {
        std::string package = argv[3];
        if (action == "install") {
        std::cout << "Installing " << package << "..." << std::endl;
        //makes sure the directory is writable
        system("sudo chown -R $USER /usr/aiopm");
        //clones the repository to /usr/aiopm/nameoftherepo
        system(("git clone https://aur.archlinux.org/" + package + ".git " + "/usr/aiopm/" + package ).c_str());
        //makes the package
        system(("cd /usr/aiopm/" + package + " && makepkg -si").c_str());
        std::cout << "Installation complete!" << std::endl;
        system("read -p 'Press Enter to continue...'");
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

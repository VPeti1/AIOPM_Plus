# AIOPM Plus
The argument based implementation of AIOPM

# How to install?
## Download the installer.out file 
Or compile it yourself
## Make it executable
sudo chmod +x installer.out
## Run it
./installer.out

# Syntax
## pm <sys,snap,flatpak,pip,flex> <install,remove,update> <package name>
## Sys: default package manager of the system 
## Snap: snap package manager 
There is no update funtions when using snap
## Flatpak: flatpak package manager 
## Pip: python package manager
## Flex: installs flex.pkg files from the repo "FlexPackages"
Extra argument: init (Installs and initializes FlexPkg)

# Syntax for arch
## pm <sys,snap,flatpak,pip,mremove,aur> <install,remove,update> <package name>
## Sys: default package manager of the system 
## Snap: snap package manager
There is no update funtions when using snap
## Flatpak: flatpak package manager 
## Pip: python package manager
## MRemove: used to remove multiple packages in archlinux 
## AUR: arch linux user repo
## Flex: installs flex.pkg files from the repo "FlexPackages"


# Known issues
## Error: std::logic_error --- You havent entered all the arguments
terminate called after throwing an instance of 'std::logic_error'
  what():  basic_string: construction from null is not valid
Aborted (core dumped)
#! /bin/bash
#
# install.sh
# 

echo "Fedora Dependency Installer for super-mario-basics"
echo "Written by Akashdeep Dhar"

echo "Installing freeglut..."
sudo dnf install freeglut-devel

echo "Installing SDL..."
sudo dnf install SDL SDL-devel SDL2 SDL2-devel SDL_image-devel

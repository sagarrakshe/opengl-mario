#! /bin/bash
#
# install.sh
# 

echo "Ubuntu Dependency Installer for super-mario-basics"
echo "Written by Akashdeep Dhar"

echo "Installing freeglut..."
sudo apt-get install freeglut3-dev

echo "Installing SDL..."
sudo apt-get install libsdl1.2-dev libsdl-image1.2-dev

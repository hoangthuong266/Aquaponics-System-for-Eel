# Aquaponics-System-for-Eel
URI (Undergraduate Research Initiative) of Arizona State University held for Vietnamese students.

Code is written in C and Python for Arduino Nano and Orange Pi Lite 2 (Armbian is recommended).
Software and Library Requirement:

1. Arduino IDE: https://www.arduino.cc/en/Main/Software

    Download Linux ARM 64 bits.
    
    cd Downloads
    
    tar xvf arduino-1.8.12-linuxaarch64.tar.xz //or file name for newer version.

    cd arduino-1.8.12

    sudo chmod +x install.sh

    sudo ./install.sh

2. WiringOP: https://github.com/orangepi-xunlong/wiringOP

    git clone https://github.com/orangepi-xunlong/wiringOP

    cd wiringOP

    ./build

3. OPi.GPIO: https://pypi.org/project/OPi.GPIO/

    sudo apt update

    sudo apt install python3-pip python3-dev

    sudo pip3 install OPi.GPIO

4. How to compile C code?

    Using Geany software (included in Armbian) is recommended, add -lwiringPi in Set Build Commands.

Install LAMP on Debian 10:

    sudo apt install apache2 php php-mysql mariadb-server mariadb-client
   
    Copy file info.php in codePHP folder to /var/www/html then access http://YOUR_PI_IP/info.php to make sure installation succeeded.
    
    Then follow this instruction to install phpmyadmin on Debian 10: https://www.linuxbabe.com/debian/install-phpmyadmin-apache-lamp-debian-10-buster
    
Install Node-RED: https://nodered.org/docs/getting-started/raspberrypi

#!/bin/bash

check_success() {
    if [ $? -ne 0 ]; then
        echo "Error: $1 failed"
        exit 1
    fi
}

echo "Installing dependencies..."
sudo apt-get update
check_success "apt-get update"

sudo apt-get install -y \
    build-essential \
    libx11-dev \
    libxext-dev \
    libxrandr-dev \
    libxinerama-dev \
    libxcursor-dev \
    libxi-dev \
    xorg \
    xvfb \
    libgl1-mesa-dev \
    bash \
    make \
    gcc \
    file \
    libbsd-dev
check_success "apt-get install"

echo "Building mlx library..."
cd bonus/libs/mlx_linux
check_success "cd bonus/libs/mlx_linux"

make all
check_success "make all in mlx_linux"

cd ../../..
check_success "cd ../../.."

echo "Building bonus part of the project..."
make bonus
check_success "make bonus"

echo "Build process completed successfully."
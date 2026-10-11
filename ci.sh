#!/usr/bin/env bash
set -euo pipefail

echo "Running CI script..."
cmake --version

echo "Configuring CMake..."
cmake -S . -B build

echo "Building project..."
cmake --build build --config Release

echo "Running tests..."
cd build
ctest --output-on-failure
cd ..

echo "CI script completed successfully"

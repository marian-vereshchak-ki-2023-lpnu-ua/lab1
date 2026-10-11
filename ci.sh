#!/usr/bin/env bash
set -euo pipefail

echo "Running CI script..."
cmake --version
cmake -S . -B build
cmake --build build --config Release
echo "CI script completed successfully"

#!/bin/bash
if [ "$EUID" -ne 0 ]; then
  echo "Error: You must run this script as root."
  exit 1
fi
destination_dir="/usr/bin"
cp rcopy rpaste rloading "$destination_dir"
echo "Installation completed successfully. You can now use the rcopy and rpaste commands."

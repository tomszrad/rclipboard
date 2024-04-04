#!/bin/bash

if [ "$EUID" -ne 0 ]; then
  echo "Error: You must run this script as root."
  exit 1
fi

destination_dir="/usr/bin"
rm -f "$destination_dir/rcopy" "$destination_dir/rpaste" "$destination_dir/rloading"
rm -rf /home/*/.config/rclipboard
echo "Uninstallation completed successfully."

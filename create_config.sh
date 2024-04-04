#!/bin/bash
config_file=~/.config/rclipboard/rclipboard_file_path
mkdir -p ~/.config/rclipboard
read -p "Enter the path: " user_path
echo "path=\"$user_path\"" > "$config_file"
echo "Configuration file created at $config_file with path: $user_path"

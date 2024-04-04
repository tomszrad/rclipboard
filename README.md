# rclipboard

Rclipboard, provides `rcopy` and `rpaste` commands that you can assign to keyboard shortcuts in Linux and use them for your own clipboard independent of the system clipboard. 
The clipboard content is stored in a file in custom path. The idea is to share the clipboard across multiple hosts via remote share, such as webdav or samba.
Personally, I use webdav set up on an apache server. This is a good solution to make the remote clipboard work over the internet. To mount a webdav share, I can recommend using [webdavfs](https://github.com/miquels/webdavfs).

## How it works?

*When copying to rclipboard:*
 1. The content of the system clipboard is copied to a temporary file in the /tmp directory.
 2. The selected text is copied to the system clipboard by xclip.
 3. The new content of the system clipboard is redirected to the remote clipboard file
 4. Previous content of the clipboard saved in /tmp is redirected back to the system clipboard
 
*When pasting from rclipboard:*
 1. The content of the system clipboard is copied to a temporary file in the /tmp directory.
 2. The content of the remote clipboard file is redirected to the system clipboard.
 3. xdotool performs the keyboard shortcut ctrl+shift+v or ctrl+v to paste the content of the clipboard.
 4. The previous clipboard content saved in /tmp is redirected back to the system clipboard.

## Note:
Because rclipboard scripts only support redirection of text strings, copying images or files is not supported. Similarly, if you have a file or image in the system clipboard and intend to use rclipboard, the content of the system clipboard will not be restored.

## Installation:
Before installing rclipboard, make sure you have `xdotool` and `xclip` installed globally.
To install them you can use:

*for arch based distros:*

    sudo pacman -S xclip xdotool

*for debian based distros:*

    sudo apt update
    sudo apt install xclip xdotool


Next, clone the repository and use installation script:

    git clone https://github.com/tomszrad/rclipboard
    cd rclipboard
    sudo chmod +x install.sh
    sudo ./install.sh
Now use script to create a configuration file. It will ask you for the path to the file where the content of the remote clipboard will be stored. For example, it can be a file in a mounted share, like /home/user/webdavshare/clipboard.

    ./create_config.sh

After that, all that remains is to create the appropriate keyboard shortcuts. Here the way to do it will depend on your desktop environment. For xfce4, you can head to the settings manager, keyboard section and Application Shortcuts tab.

You'll need three keyboard shortcuts:
- For copying a selection to the remote clipboard: `rcopy`
- For pasting the content of the remote clipboard: `rpaste`
- For pasting the content of the remote clipboard inside terminal: `rpaste shift`

In my case it looks like this:

![shortcuts screenshot](https://raw.githubusercontent.com/tomszrad/rclipboard/main/shortcuts_screenshot.png)

Once the shortcuts are created, you can start using the remote clipboard :)

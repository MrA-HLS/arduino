# The Amunrud VSCode / Git / Arduino setup guide

1. You've already completed the first step: finding these instructions!
## Software
Find and install all of the required software (If you're using the lab, this has already been done for you)
- Visual Studio Code from Microsoft <https://code.visualstudio.com/>
- Git for Windows <https://git-scm.com/downloads>
- Arduino IDE (do not use the Windows App from the store!) <https://www.arduino.cc/en/main/software>
## Setup VS Code
### Install some basic extensions for VS Code:
- C/C++
- GitLens (optional, but very helpful for larger projects)
- Arduino
- Visual Studio IntelliCode / intellisense (optional again, but helpful for C/C++)
### Configure VS Code:
1. VS Code has many ways to change settings: one of it's most powerful tools is the 'command palette.' Press "Ctrl+Shift+P" or F1 to open the command pallete.
2. Use the command palette to select a sensible default shell:
    - start typing `terminal: select default shell` into the command pallete. It should autocomplete as you type. You can hit enter on it or click it once you see it.
    - select Git Bash from the list of available shells
3. Start a new Terminal-we will need it soon.
**NB** One thing that makes VSCode so great is it's helpful suggestions and auto-configuration. As you work with the program, don't ignore it's suggestions. Read them and use them if they will help you.
### Git and github.com 
For class exercises, we will be using github.com. It's a good platform for sharing small projects.
1. If you don't have an account, create one.
2. Make sure you give me your username or email so I can add you as a collaborator to the class repository.
3. We are going to set up ssh authentication for git hub:
    Follow the instruction at <https://help.github.com/en/enterprise/2.18/user/github/authenticating-to-github/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent> 
    Use the terminal we opened earlier in VS Code. I usually don't use passphrases with ssh keys.
4. Test that your ssh key is working by running `ssh git@github.com` in your terminal. You should get a message that you have successfully authenticated.
## Setting up the project
Both git and VS Code (conveniently) use a root folder to organize a project. You will need to decide where to put this folder. All of the code for the project will get copied into this folder. Likewise, anything you add to the folder will probably end up shared with everyone working on the project. A sensible location might be `u:/Documents/arduino`. 

Run `git clone git@github.com:MrA-HLS/arduino.git u:/Documents/arduino` from the terminal. Use your own location if you like. This will download a copy of the project to the specified folder and start your own local git repository.

Run `cd ~/Documents/arduino` to **c**hange **d**irectory to the one you just created and then `git checkout master`


Open the folder you just created in VS Code by selecting `Open Folder` from the `File` menu. If you like, you can now use the command palette to manage all of the git commands instead of the terminal. Once your folder is open, you can save the workspace to a file to quickly get all of your settings back if you close VS Code.

From the VS Code explorer, open one of the .ino arduino program files. VS Code should automatically recognize the C++ formatting. You can see the language it has selected and change it from the blue bar in the bottom. Configure the Arduino extension by running `Arduino: Initialize` from the command palette. We are using a Mega 2560 clone. From the blue bar at the bottom of VS Code, select the programmer `AVRISP mkii`. If the arduino is plugged in, you can also select the serial port.

There is a bug with VS Code that keeps it from finding some of the header files we want to include. Edit the `c_cpp_properties.json` file and add `"C:\\Program Files (x86)\\Arduino\\hardware\\tools\\avr\\**"` to the list of `"includePath"` options. Don't forget to add a comma.
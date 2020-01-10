# The Amunrud VSCode / Git / Arduino setup guide

You've already completed the first step: finding these instructions!
## Software
Find and install all of the required software (If you're using the lab, this has already been done for you)
- Visual Studio Code from Microsoft <https://code.visualstudio.com/>
- Git for Windows <https://git-scm.com/downloads>
    - You may need to log out and log in again before Git will work fully.
## Setup VS Code
### Install some basic extensions for VS Code:
You can navigate to the main sectinos of VS Code via the nav bar on the upper left side of the window. Find the extension manager. By default, I think it's the fifth from the top; that may change as you add extensions.
Search for and install the following extensions. As they install, they may launch info pages or settings pages for you to customize options
- C/C++
- PlatformIO IDE
- GitLens (optional, but very helpful for larger projects)
- Visual Studio IntelliCode / intellisense (optional again, but helpful for C/C++)

### Configure VS Code:
1. VS Code has many ways to change settings: one of it's most powerful tools is the 'command palette.' Press "Ctrl+Shift+P" or F1 to open the command palette. Almost anything you might want to do can be done from the command palette
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

Let's start with the LED_Basics project: Open this project by
- Go to the PIO Home page. You can navigate from the left navigation or select `PlatformIO: Home` from the command palette.
- Select the option to 'Open a Project'
- Browse to the folder you just created
- Open the "LED_Basics" folder

### Project Organization
There can be a lot of files in a project. Most of these need not concern you much yet. 
- platformio.ini contains the information about which board/device(s) the project targeting and build options. This is the best place to indicate which libraries your project requires. You should be able to see that the LED_Basics project uses the rgb-led library.
- src/main.cpp is the default location of the main c++ code file

### Building and Running Projects
Open the main.cpp file. It should look familiar. Read through the entire file until you are comfortable with what it does.
When you are ready, you can build the project by selecting the blue check mark in the blue bar at the bottom of VS Code. Once you've successfully built the project, write it to the arduino by connecting the USB to your station/computer and selecting the 'Upload' arrow next to the check mark.


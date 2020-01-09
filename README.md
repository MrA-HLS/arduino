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
- **NB** One thing that makes VSCode so great is it's helpful suggestions and auto-configuration. As you work with the program, don't ignore it's suggestions. Read them and use them if they will help you
### Git and github.com 
For class exercises, we will be using github.com. It's a good platform for sharing small projects.
1. If you don't have an account, create one.
2. Make sure you give me your username or email so I can add you as a collaborator to the class repository.
3. We are going to set up ssh authentication for git hub:
    Follow the instruction at <https://help.github.com/en/enterprise/2.18/user/github/authenticating-to-github/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent> using the terminal we opened earlier in VS Code. I usually don't use passphrases with ssh keys.
4. Test that your ssh key is working by typing `ssh git@github.com`. You should get a message that you have successfully authenticated.
## Setting up the project



# Language Overview and Setup
## A Brief History of C++
In the 1970s, object-oriented programming (OOP) experienced a rapid increase in popularity. In response, Bjarne Stroustrup began developing an OOP-supporting successor to C at Bell Laboratories in Murray Hill, New Jersey (Schildt 5). Stroustrup further expanded "C with Classes" to include improved type checking, operator overloading, and virtual functions (Rassokhin 2). In 1983, Stroustrup renamed "C with Classes" to C++, and three years later, he published his reference manual, The C++ Programming Language (Rassokhin 2). 

Today, C++ has a wide range of applications including video games, GUI-based programs (including Adobe), database software (including MySQL and Postgres), operating systems (including Apple OS and Microsoft Windows OS), and browsers (including Mozilla Firefox and Google) (Xiao).

## Getting Started
Before diving into the coding, we will need to install an integrated development environment (IDE). Visual Studio Code is widely considered the best IDE for C++, as it is free to download, easy to navigate, and provides a robust debugger. Note that the following instructions are specific to Windows.
#### Installing Visual Studio Code
1. First, navigate to the Visual Studio Code download page using your browser of choice or by following this [download link](https://code.visualstudio.com/download).
2. Choose the approprate operating system. Note that this tutorial assumes a Windows operating system.
3. Once the download finishes, open the VS Code user setup .exe file.
4. Accept the license agreement.
5. Next, the installer will ask for the destination folder PATH. This can be left as the default PATH or updated to a location of choice. Confirm the installation destination by clicking "Next". 
6. The window will then present a series of additional setup options. Again, this can be left as the default or customized. To proceed, click "Next".
7. Finally, make sure VS Code is set to open when complete and click "Finish". 
#### Adding the C/C++ Extension to VS Code
1. Once Visual Studio Code opens, hit Ctrl+Shift+X or select the "Extensions" tab on the activity bar.
2. Search for C++.
3. Click on C/C++ and select "Install".
#### Installing MinGW-x64
Next, we will install the necessary tools for compiling and building C++ programs in VS Code.
1. Navigate to the MSYS2 download page using your browser of choice or by following this [download link](https://github.com/msys2/msys2-installer/releases/download/2022-06-03/msys2-x86_64-20220603.exe).
2. Run the installer and enter the desired destination folder PATH. Again, this can be  left as the default.
3. After clicking "Finish", the UCRT64 environment should launch in the terminal window.
4. Next, add the Mingw-w64 bin folder to the Windows PATH environment variable. To do this...
   - Keep the terminal open and navigate to Windows Settings.
   - Search for "environment" and select "edit environment variables for your account". Make sure to choose "edit environment variables for your account" and NOT      "edit the system environment variables".
   - Under the box labeled "User variables for {your account name}" click "New" and add the Mingw-w64 destination folder PATH as the variable value. Note that if 
     the destination folder was left as the default PATH, the value should be C:\msys64mingw64\bin.
   - Click "Okay" and return to the terminal window.
5. In the terminal window, install the Mingw-w64 toolchain by running the following command: `pacman -S --needed base-devel mingw-w64-x86_64-toolchain` and accept the default to add all members in the toolchain group.
6. Finally, to verify that all the necessary tools were installed correctly, open a new terminal and check the versions of gcc, g++ (the gcc compiler), and gdb (the debugger) by executing the following commands: `gcc --version`, `g++ --version`, and `gdb --version`.
#### Running "Hello World"
Executing code in Visual Studio Code works the same regardless of the language. First, the program must be saved with the appropriate file extension. For C++ specifically, the file name must have the .cpp extension. Next, simply execute the code by hitting Ctrl+F5 or by clicking the play button in the upper right corner of the window. Try running the following code to test if everything from the previous steps installed correctly. Note that comments in C++ are denoted using a double slash `//`. 
```
\\ C++ Hello World Program provided by Connor Peet of Visual Studio Code

# include <iostream>

int main()
{
  std::count << "Hello World" << std::endl;
}
```

# Reo Engine
Calling all aspiring game creators! Reo Engine is your gateway to crafting captivating 2D and 3D games. Built using C++ and OpenGL, this beginner-friendly engine provides a solid foundation to bring your game ideas to life.

Focus on the heart and soul of your game – the gameplay and visuals – while Reo Engine handles the technical nitty-gritty.

## How To Run

Make sure to install the following:

MinGW (Windows): A free and open-source compiler suite for Windows. Download it from https://www.mingw-w64.org/.

Visual Studio Code: A free and open-source code editor with extensive C++ support. Download it from https://code.visualstudio.com/.

**After installation, add MinGW to your system environment variables.**

Then you can just run the engine by pressing F5 in Visual Studio Code.

> Note: This is a basic setup guide. More detailed instructions might be needed depending on your specific environment.

**Make sure to copy the required DLLs and the uesd folders in src/ to the build directory** 

### Manage Script
'manage.py' is a python script that allow you to compile and build the project with specific folders
```bash
python manage.py build
```
You can use -h option to get information and more details about the option 
```bash
python manage.py -h
```
The build structure should be like that: 

---- build/

-------- shaders/

-------- fonts/

-------- app.exe    

-------- glfw3.dll  

-------- freetype.dll
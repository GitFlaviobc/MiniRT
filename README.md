# Mini Ray Tracing

<h1 name ="content" align = "center">📋 Table of contents</h1>
<p align = "center">
  <a href = "#intro">Intro</a> -
  <a href = "#goal">Goal</a> -
  <a href = "#tec">Tecnology</a> -
  <a href = "#function">Functionality</a> -
  <a href = "#how">How to use</a> -
  <a href = "#test">Tests</a> -
  <a href = "#update">Update</a> -
  <a href = "#author">Author</a>
</p>

<a name="intro"/> <h2> Intro </h2> </a>
- This is a project about Ray Tracing.
- On this project I learned about the basics of ray tracing, vectors, matrices, all the math behind the camera, shapes, materials, colors, shadow and light.
- This is only a basic ray tracing, an intro to a complex and fun topic.
- I set the scene in the .rt files, read, parse, do the math of a 3D space, and allocate the memory to all pixels on the screen, after that I use the minilibx (that uses X11) to create the window with the image.
<p></p>
<a href = "#content">📋</a>

<a name="goal"/> <h2> 🎯 Goal </h2> </a>
- Create a scene with Ambient Light, Camera, Point Light and objects
- The objects are set by using their respective math formulas and the given parameters after parse the .rt file.
- The objects are: Infinity plane, Sphere, Open Cylinder.
- Once all objects are set, the camera will use the ray tracing logic to determine how to show all the objects in screen.
- The ray tracing is able to check postion in the 3D space, material colors, shadow points and how the lights color will affect each object final rendering.
- While doing all the math, each pixel information is being allocated in a continuous memmory.
- Once it is done, all the info is transleted with minilibx (X11), to rende the window and the pixels inside of it.

<p></p>
<a href = "#content">📋</a>

<a name="tec"/> <h2> 🛠️ Tecnology </h2> </a>
- Language: C
- VS code
- WSL ubuntu
- VNC 
- Norminette 42 (code norm used by école 42)
<p></p>
<a href = "#content">📋</a>

<a name="function"/> <h2> 📚 Functionality </h2> </a>

![Philosophers Example]

<p></p>
<a href = "#content">📋</a>

<a name="how"/> <h2> 📖 How to use </h2> </a>
⚠️ This is a graphic project so you need a VNC or something to be able to visualize the scenes.
- Clone the repository
```bash
git clone https://github.com/GitFlaviobc/MiniRT.git
```
- to create the miniRT (Inside Project folder)
```bash
make
```
or
```bash
make all
```
- to delete all obj (.o) files created
```bash
make clean
```
 - to delete all created files
```bash
make fclean
```
 - to delete all files and recreate the miniRT
```bash
make re
```
- Args: .rt File
- Example:
```bash
./miniRT scenes/final.rt
```
<p></p>
<a href = "#content">📋</a>

<a name="test"/> <h2> 👨‍💻 Tests </h2> </a>
- Check for invalid rt files
```bash
make errors
```
- Use valgrind to check for leaks.
<p></p>
<a href = "#content">📋</a>

<a name="update"/> <h2> 🆙 Updates </h2> </a>
⚠️🚧
<p></p>
<a href = "#content">📋</a>

<a name="author"/> <h2> 😀 Author </h2> </a>
Name: Flávio Bonini Campos
<p></p>

[![Linkedin](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/flaviobc88/)
<p></p>
<a href = "#content">📋</a>
<p></p>

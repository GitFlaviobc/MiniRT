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
- All elements are set by using their respective math formulas and the given parameters after parse the .rt file.
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

<img src="https://developer.nvidia.com/sites/default/files/pictures/2018/RayTracing/ray-tracing-image-1.jpg" width="500">
<img src="https://www.povray.org/documentation/images/reference/perspcam.png" width="500">

<h3>⚠️ To Allow Multiplie Lights, comment or delete the lines of the file bellow ⚠️</h3>

[Lines in the File](https://github.com/GitFlaviobc/MiniRT/blob/ceb673212a9fec8aff7861bf06b3951d03a303d9/Project/src/parser/ft_elements_to_scene.c#L83-L84)

<p></p>

<ins>
<p> <h2> Elements Attributes Table </h2> </p>
<p> <h4> All given numbers are just examples. </h4> </p>
<p> <h4> The attributes values must be inside the limits range, when it has one. </h4> </p>
</ins>

Element        | Identifier   | Intensity   | Intensity Limits     | Color         | Color Limits 
---            | ---          | ---         |---                   |---            |--- 
Ambient Light  | A            | 1           | [0,1]                | 255,255,255   | [0,255]

Element      | Identifier   | Position    | Position Vector       | Intensity    | Intensity Limits    | Color        | Color Limits
---          | ---          | ---         |---                    |---           |---                  |---           |---
Point Light  | L            | 1,0,0       | (x,y,z)               | 1            | [0,1]               | 255,255,255  | [0,255]

Element    | Identifier   | Position    | Position Vector       | Look at    | Look at Vector | Look at Vector Limits   | FOV | FOV Limits
---        | ---          | ---         |---                    |---         |---             |---                      |---  |---
Camera     | C            | 0,0,0       | (x,y,z)               | 0,0,-1     | (x,y,z)        | [-1,1]                  | 45  | [0,180]

Element      | Identifier   | Position    | Position Vector       | Diameter    | Color        | Color Limits
---          | ---          | ---         |---                    |---          |---           |---
Sphere       | sp           | 0,0,0       | (x,y,z)               | 0.2         | 255,255,255  | [0,255]

Element               | Identifier   | Position    | Position Vector       | Normal  | Normal Vector | Normal Vector Limits  | Color        | Color Limits
---                   | ---          | ---         |---                    |---      |---            |---                    |---           |---
Inifinity Plane       | pl           | 0,-1,0      | (x,y,z)               | 0,1,0   | (x,y,z)       | [-1,1]                | 255,255,255  | [0,255]

Element        | Identifier   | Position    | Position Vector       | Normal  | Normal Vector | Normal Vector Limits  | Diameter | Height | Color        | Color Limits
---            | ---          | ---         |---                    |---      |---            |---                    |---       |---     |---           |---
Cylinder       | cy           | 0,-2,0      | (x,y,z)               | 0,1,0   | (x,y,z)       | [-1,1]                | 0.1      | 0.3    | 255,255,255  | [0,255]


<p> <h3>⚠️ I lost image quality while making the gif ⚠️</h3> <p>

<img src="https://github.com/GitFlaviobc/MiniRT/blob/47e0fe7744cb843954d2ab788981b7008a13cf1b/Images/MiniRT.gif" width="500">
<p></p>
<a href = "#content">📋</a>

<a name="how"/> <h2> 📖 How to use </h2> </a>
⚠️ This is a graphic project so you need a VNC or something similar to be able to visualize the scenes. ⚠️
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
- Examples of Invalid rt files / User input
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

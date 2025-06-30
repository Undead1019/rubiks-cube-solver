Rubik’s Cube Cracker
====================

Rubik’s Cube Cracker is a real-time, interactive 3D Rubik’s Cube simulator and solver developed in C++ with OpenGL.
It integrates high-performance rendering with intelligent solving algorithms, providing both a visual and computationally rich experience.

Key Features
------------

• Real-time 3D Cube Interaction  
  - Rotate cube faces using intuitive keys (U, D, L, R, F, B)  
  - Spin the entire cube in 3D using arrow keys and ‘Z’ axis rotations

• Animated Transitions and Shading  
  - SLERP-based face animations using quaternions  
  - Phong lighting with procedurally generated sticker textures and subtle imperfections  
  - Floating cube effect to add realism

• Dual Solvers  
  - Korf’s Algorithm (Optimal Solver):  
    > Guarantees solution in 20 moves or fewer using IDA* search with massive pattern databases  
  - Thistlethwaite’s Algorithm (Fast Solver):  
    > Solves any scramble almost instantly with up to 46 moves using multi-stage reduction and heuristic databases

Controls
--------

| Action              | Key                                    |
|---------------------|-----------------------------------------|
| Rotate Cube Faces   | U, D, L, R, F, B (+ SHIFT, ALT)         |
| Rotate Whole Cube   | Arrow Keys, Z (+ SHIFT for prime)       |
| Slice Moves         | M, E, S                                 |
| Random Scramble     | F5                                      |
| Solve (Fast)        | F1 (Thistlethwaite)                     |
| Solve (Optimal)     | F2 (Korf)                               |

Technical Highlights
--------------------

- Written in C++ with OpenGL and GLSL shaders
- Implements IDA* search with large pattern databases (~750MB total)
- Efficient indexing using Lehmer codes for permutation-to-index mapping
- Real-time animation and lighting developed from scratch

Build Instructions
------------------

• Linux (preferred): Compile with g++ and OpenGL libraries  
• Windows: Tested with MinGW-w64 toolchain

See `BUILDING.md` for setup and compilation steps.

My Journey with the Cube
------------------------

This project is personal.

I was an avid speedcuber during my school days. There was a time when solving a Rubik’s Cube in under 20 seconds felt like second nature. But during the demanding years of JEE preparation, I had to leave cubing behind. When I tried to return to it after years, my fingers hesitated, and the cube felt unfamiliar.

That moment sparked an idea: what if I could recreate the cube virtually—better yet, teach it to solve itself optimally? I didn’t just want to simulate a cube. I wanted to combine graphics, math, and AI into a system that reflects both the puzzle and my journey with it.

Rubik’s Cube Cracker became my way to reconnect—with the cube, with code, and with the joy of solving.

YouTube Demo
------------

Watch the demo here: https://www.youtube.com/watch?v=ZtlMkzix7Bw&feature=youtu.be

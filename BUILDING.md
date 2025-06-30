
# Rubik’s Cube Cracker – Build & Environment Guide

## Environment

Rubik’s Cube Cracker was developed on Linux but is also compatible with Windows. It can be built using standard OpenGL libraries or within a Docker container.

---

## 🔧 Using Docker (Recommended)

For a seamless setup, especially on Linux systems with NVIDIA GPUs:

> **Pre-requisite:** Install the [NVIDIA Container Toolkit](https://github.com/NVIDIA/nvidia-docker) to enable OpenGL support inside Docker.

### Run Development Environment

```bash
./Docker/run-dev-env.sh
```

The code will be mounted to `/var/src/` inside the container.

### Build Docker Image

Provide a version number when building:

```bash
./Docker/build.sh 4.0.1
```

---

## 🧱 Manual Build (Without Docker)

If you prefer not to use Docker, follow the setup below. The `Docker/Dockerfile` contains all dependencies and can be used as a reference.

### Dependencies

#### GLFW (v3.3.3)

```bash
wget https://github.com/glfw/glfw/releases/download/3.3.3/glfw-3.3.3.zip
unzip glfw-3.3.3.zip
cd glfw-3.3.3
mkdir build && cd build
cmake -DBUILD_SHARED_LIBS=ON ..
make -j4
sudo make install
cd ../../ && rm -rf glfw*
```

> Installed to `/usr/local/lib/` and `/usr/local/include/`

#### GLM (v0.9.8.5)

```bash
wget https://github.com/g-truc/glm/releases/download/0.9.8.5/glm-0.9.8.5.zip
unzip glm-0.9.8.5.zip
sudo cp -R glm/glm /usr/local/include/
rm -rf glm*
```

> Installed to `/usr/local/include/`

#### GLEW (v2.2.0)

```bash
wget https://github.com/nigels-com/glew/releases/download/glew-2.2.0/glew-2.2.0.zip
unzip glew-2.2.0.zip
cd glew-2.2.0
make -j4
sudo make install GLEW_DEST=/usr/local
cd .. && rm -rf glew*
```

> Libraries in `/usr/local/lib64/`, headers in `/usr/local/include/GL/`

---

## 📂 Pattern Databases

Pattern databases (~1GB total) are required for solving algorithms.

- Uses **git-lfs**. Install it from [https://git-lfs.github.com](https://git-lfs.github.com) **before cloning** the repository.
- Alternatively, the program will auto-generate them if the `Data/` folder is empty — but this may take **several hours**.

---

## 🏗️ Building the Project

Use an **out-of-tree** build:

```bash
mkdir build && cd build
cmake ..
make -j4
cd ..
```

Run the application from the **base directory** to ensure paths are correctly resolved:

```bash
./build/rubiksCube
```

---

## 🐞 Debugging Build

Build in Debug mode:

```bash
mkdir debug && cd debug
cmake -DCMAKE_BUILD_TYPE=Debug ..
make -j4
cd ..
```

Run with GDB:

```bash
gdb ./debug/rubiksCube
```

---

Happy Cubing! 🧩

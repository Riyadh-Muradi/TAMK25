# C++ Beginner Environment (Docker)

---

### See 📺 [Quick Start!](https://youtu.be/xV1MkSmqhTU)

---

## IDE vs Docker + Clang

You have started to learn the concepts using professional IDE like Clion. That approach is widely used and completely valid, especially when the goal is to help students become productive quickly.

In this part of the course, the goal is slightly different.

Our focus is on **making the fundamentals visible first**, before relying on advanced tools that automate many steps.

This approach can be more complicated but we do at a reason

- Understanding what happens running an program
- Everyone has the same environment: Linux and Clang
- Learning the terminal is a core skill, expecially Linux
- By writing everything manually instead of AI and auto completion you will gain a deeper understanding

## What you need

- [**Docker Desktop**](https://www.docker.com/products/docker-desktop/) (Windows/macOS) or Docker Engine (Linux)
- A terminal (PowerShell/Command Prompt on Windows, Terminal on macOS/Linux)
- [`Dockerfile`](./Dockerfile) - file
- [`run.bat`](./run.bat) or [run.sh](./run.sh) file

Optional

- [`compile.sh`](./compile.sh) file for easier compiling

## Quick start

- [Install Docker Desktop](https://www.docker.com/products/docker-desktop/) and start the Docker
- Download [`Dockerfile`](./Dockerfile) and [`run.bat`](./run.bat) or [run.sh](./run.sh) file
  - `.bat` → win, `.sh` → macOS or linux
- Place the `Dockerfile` and `run.sh|.bat` file to some directory
- Open terminal within that directory
- Run the script either: `./run.sh` or `run.bat`

The script will build the Docker image and open a shell inside the container. Basically it will create a linux environment with clang compiler and nano text editor.

Once ready you will be inside of Linux operating system and you will have a C++ compiler (clang) and Nano - text editor.

## Inside the container

### Edit files:

```
nano mycode.cpp
```

`ctrl-w` saves, `ctrl-o` exits

### Compile:

```bash
clang++ -std=c++20 -Wall -Wextra mycode.cpp -o application
```

### Run:

```bash
./application
```

What?

- `-std=c++20`: Use the C++20 language standard.
- `-Wall`: Enable a broad set of useful warnings.
- `-Wextra`: Enable additional warnings beyond `-Wall`.
- `-o application`: Set the output file name (the compiled program).

Since this is a rather long command you can do it a bit easier.
Download a [`compile.sh`](./compile.sh) file which will give the same command:

```bash
compile.sh mycode.cpp application
```

### Exit:

```
exit
```

## Gif - animations

### Windows

![windows docker usage](./windows.gif)

### macOS

![mac docker usage](./mac.gif)

## Troubleshooting

- “Docker not installed” or “Docker not running”:
  Install/start Docker Desktop and try again.
- If `./run.sh` says “permission denied”:
  Run `chmod +x run.sh` and try again.

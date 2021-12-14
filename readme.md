# 数据结构实验

本项目是 NUAA 2021秋季学期数据结构实验和课程设计源代码，包含题目要求pdf文件，代码逻辑基本正确，但没有得到严谨验证，有问题可以提issue。

其中 lab1~lab8 为平时上机实验的代码。

# Software requirements
```
$ gcc -v
gcc version 8.1.0 (x86_64-posix-seh-rev0, Built by MinGW-W64 project)
$ (Get-ItemProperty -Path c:\windows\system32\hal.dll).VersionInfo.FileVersion
10.0.19041.1151 (WinBuild.160101.0800)
```
# 上手指南

下载代码后，一般通过如下命令运行cpp源文件，以运行 4CSp.cpp 为例：
```
g++ 4CSp.cpp -o 4CSp.exe;./4CSp.exe
```

但对于源文件有自定义头文件的源文件涉及多文件编译，使用 各个目录下的makefile文件进行编译，注意按需求修改 makefile 文件，修改后使用：
```
clear;make clean;make run
```
运行代码。
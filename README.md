# HEEModByPuls
High-Energy Electrons Modulated By geomagnetic Pulsations

## Style guide
We use "Google C++ Style Guide"
ref::https://google.github.io/styleguide/cppguide.html
(Jp::https://ttsuki.github.io/styleguide/cppguide.ja.html#Doing_Work_in_Constructors)

## Prohibit push to master
You should put pre-push file(like pre-push file in pre-push_template directry) in ./git/hooks

and do the following
```
chmod 775 pre-push
```

## VSCode Extensions
### CMake
for CMake
### CMake Tools
Super CMake tooooool
### C/C++(from Microsoft)
easy coding!
### PlantUML
for PlantUML on VSCode

### Markdown Math
for document

### Markdown Preview Enhanced
for document

### Python
for graph(matplotlib)

## VSCode Extensions(not must)
### Git History
(something for git)

## Install List
Attention! if you use WSL2, you should install all software in WSL2.
### CMake
  for CMake
### compiler 
  c++ compiler(ex.g++,clang10)
### Java
  for PlantUML
### graphviz
  for PlantUML

### google chrome
  for Markdown Preview Enhanced

### matplotlib
for graph(recommend installation via pip3)

### numpy
for matplotlib(recommend installation via pip3)

### pandas
for matplotlib(recommend installation via pip3)

## Install List(not must)
###pylint

Probably recommended by VSCode. Linter for python

## Documentation file
  usu md file
  in VSCode, Ctrl K →V(preview)


## How to use matplotlib on WSL2(2021/04/12)
It is assumed that numpy and matplotlib are installed and Python Extension is installed on VSCode

1. Install VcXsrv(on Windows)
2. Execute xlaunch.exe
3. Choose multiple window
4. Start no client
5. write "-ac -nowgl"  on Additional parameters for VcXsrv   
5. Save configuration to somewhere(ex. Desktop)
6. Finish xlaunch 
7. Windows key + r  and type in shell:startup
8. A folder called Startup will open, so move the file created using xlaunch to this location

9. Open WSL2
10. Open ~/.bashrc
11. Add the following command to the last line of the opened .bashrc and save it.

```

export DISPLAY=$(cat /etc/resolv.conf | grep nameserver | awk '{print $2}'):0
```
12. Run the following code on WSL2

```
sudo apt-get install python3-gi-cairo
```

13. Reload WSL2

### if matplotlib does not work

14. 
 Run the following code on WSL2

```
 sudo apt install python3-tk
 sudo apt install tk-dev
```

reference
https://qiita.com/ryoi084/items/0dff11134592d0bb895c
https://qiita.com/masa-tu/items/20111878476bb97a9d07
https://qiita.com/optimisuke/items/bb47c4354d2513d1d173
https://ai-gaminglife.hatenablog.com/entry/2019/04/29/204841
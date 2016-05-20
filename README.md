# AI Paths
AI Paths is a program made in C++ using SFML, the writer's first attempt at such athing.


This project is part of the course in [Introduction to Artificial Intelligence] at [ntua] and is non-commercial.

# Alright, and what exactly is this?
It takes data from another program (not in repos but might upload soon) 
that calculates paths for two agents using A* in a 2D map, and draws their movement in a 2D tileMap.

Some of the things learned from this:
- Drawing of a tileMap (textures)
- Drawing of 2D sprites in the above map , and animating according to movement, by recycling a 2D sprite strip.


# Installation (Linux/MAC x86_64)
To install you have to have the SFML libraries installed for your system and some openGL libraries which should already be installed.
Then run `make` with the Makefile provided and then use the bash script `./run test.txt` which is also provided
along with a sample testcase file called 'test.txt'.



## SFML
To install smfl libraries please check with the repositories of your current distribution. Some examples:

### Ubuntu 

```
sudo apt-get install libsfml-dev
```
More info [here]
### Arch (AUR)
```
sudo pacman -S sfml
```

If you run into problems please dont hesitate to contact me.



[//]: # (These are reference links used in the body of this note and get stripped out when the markdown processor does its job. There is no need to format nicely because it shouldn't be seen. Thanks SO - http://stackoverflow.com/questions/4823468/store-comments-in-markdown-syntax)
   [ntua]: <http://ece.ntua.gr>
   [Introduction to Artificial Intelligence]: <http://www.ece.ntua.gr/en/education/undergraduate?view=ugcourse&id=83>
   [here]: <http://www.sfml-dev.org/tutorials/2.0/start-linux.php>

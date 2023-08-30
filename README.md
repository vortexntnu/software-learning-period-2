# software-learning-period-2
A repository dedicated to the Vortex NTNU software members to mess around with Git and to learn ROS 2

---

 This is a tutorial to how some fundamental concepts of ROS works. More spesifically, you will learn how to:

* set up a workspace 
* run a node
* listen to a topic
* create a node for publishing to a topic
* create a node for subscribing to the same topic
* create a launch file for automatically launching the nodes

Commands needed for the tutorial can be found at the bottom of the document. 
### Installing ROS, catkin and vscode
Follow the steps in the ROS-wiki, and install the "Desktop version":
http://wiki.ros.org/noetic/Installation/Ubuntu

To install visual studio code on you linux computer:
https://code.visualstudio.com/download

### For Mac and other non-linux OS
If you do not have or are unable to use linux, you can use Docker to complete this tutorial. 

To download Docker Desktop, follow the steps in https://www.docker.com/ for the OS you are using. Make sure docker is running by following the guide to the end.

Edit the docker-compose file, the compose file will produce a docker container with a shard volume (storage) between your computer and the container. A shared volume allows you to edit ROS files normally (on your computer regardless of OS) and run ROS commands within the Docker container based on the files you edited. To achieve this you need to edit the file path within the docker-compose file, so the container knows which files are to be shared. When the docker-compose file is edited, use the command
```
docker compose up -d
```
, this will target the docker-compose.yml file and produce a docker container. Use docker desktop's GUI or the command 
```
docker ps
```
to find the name of the docker container. By default, the container name should be *software-training-period*.

To enter the container and execute commands, input the command
```
docker exec -it <container-name> /bin/bash
```

You are now inside of the docker container - this enables you to use all of the linux commands and ROS, as if you would be using a linux machine. When the tasks ask you to open a new terminal window, open a new terminal window and exec into the container again. If you need to run any commands with administrator privileges (i.e. sudo), the user password is "vortex". 

## Preliminaries

ROS is short for Robot operating system. This is the middleware we use on our drones to communicate between all our systems. ROS allows for programs to communicate over a defined API with ROS messages and services. It enables programs to run on multiple computers and communicates over the network. ROS modules can also run on different laguages such as C++ and Python.

**Catkin** is the build system for ROS. The tutorial will not go in depth on exactly how catkin works, but for those interested you can read up on catkin here: https://nu-msr.github.io/me495_site/lecture02_catkin.html

This tutorial will mainly focus on nodes. A node is a single purpose executable program organized in packages. Nodes communicate over topics, which again is a name for a stream of messages. 

ROS has its own standard messsages and services (you will learn about services later), but it is also possible to create your own custom messages and custom services.

It is recommended to have a look at the ROS lecture slides at found at the university of zurich if you want a good primer to what ROS is and how it works.
https://rsl.ethz.ch/education-students/lectures/ros.html

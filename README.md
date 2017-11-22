## Overview

This program implements a simple walker algorithm much like a Roomba robot vacuum cleaner. The robot  move forward until it reaches an obstacle (but not colliding), then rotate in place until the way ahead is clear, then move forward again and repeat.
Also practice the record and playback of rosbag

## Build

In terminal, go to your workspace/src

```bash
$ git clone https://github.com/ytlei/move_turtle.git
$ cd ~/catkin_ws/
$ catkin_make
```

## Run

make sure roscore is running

```bash
$ roscore
```

in another terminal

```bash
$ cd ~/catkin_ws
$ source ./devel/setup.bash
```

To record the recorded bag file, you have to enable the enable_record flag in launch file while calling the launch

```bash
roslaunch move_turtle move_turtle.launch enable_record:=true
```

## Playback

To play the recorded bag file

```bash
cd ~/.ros/
rosbag play session.bag
```

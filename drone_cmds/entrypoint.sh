#!/bin/bash

# Source ROS setup files
source /opt/ros/humble/setup.bash
source ~/drone_control/install/local_setup.bash


# If no command is provided, start a shell
if [ $# -eq 0 ]; then
    exec bash
else
    exec "$@"
fi


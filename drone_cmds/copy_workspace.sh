#!/bin/bash

# Defined container name
CONTAINER_NAME="drone-cntr"

# Defined the source path inside the container
SOURCE_PATH="/root/drone_control"

# Defined the destination path on the host
DESTINATION_PATH="/home/maximelio/ros2-drone-repo/drone-ros2-workspace"

# Copy the ROS workspace from the container to the host
docker cp "$CONTAINER_NAME:$SOURCE_PATH" "$DESTINATION_PATH"

echo "ROS workspace copied from $CONTAINER_NAME to $DESTINATION_PATH"


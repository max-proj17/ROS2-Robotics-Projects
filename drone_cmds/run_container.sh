#!/bin/bash

# Start the Docker container with volume mount and custom entrypoint
#!/bin/bash

# Start the Docker container with volume mount, custom entrypoint, and a fixed name
docker run -it --rm \
    --name drone-cntr \
    -v /home/maximelio/ros2-drone-repo/drone_cmds:/root/drone_cmds \
    -v /home/maximelio/ros2-drone-repo/drone_cmds/entrypoint.sh:/entrypoint.sh \
    --entrypoint /entrypoint.sh \
    drone-ros2-gazebo




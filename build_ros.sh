#!/usr/bin/env bash
echo "Building ROS nodes"

cd Examples/ROS/ORB_SLAM2
rm -rf build
mkdir build
cd build
cmake .. -DROS_BUILD_TYPE=Debug
make clean
make -j 4

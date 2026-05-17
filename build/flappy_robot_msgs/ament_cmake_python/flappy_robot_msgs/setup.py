from setuptools import find_packages
from setuptools import setup

setup(
    name='flappy_robot_msgs',
    version='0.0.1',
    packages=find_packages(
        include=('flappy_robot_msgs', 'flappy_robot_msgs.*')),
)

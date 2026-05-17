from setuptools import setup
import os
from glob import glob

package_name = 'flappy_robot'

setup(
    name=package_name,
    version='0.0.1',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', glob('launch/*.py')),
        ('share/' + package_name + '/msg', glob('msg/*.msg')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Your Name',
    maintainer_email='you@email.com',
    description='Flappy Robot ROS2 Mini Project',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
    'console_scripts': [
        'keyboard_controller = flappy_robot.keyboard_controller:main',
        'game_logic = flappy_robot.game_logic:main',
        'visualization = flappy_robot.visualization:main',
        'game_window = flappy_robot.game_window:main',
    ],
},
)

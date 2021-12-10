# Pololu Dagu Wild-Thumper 6WD

[<img src="https://a.pololu-files.com/picture/0J2312.600x480.jpg?a343d9a91106a34914708601bcadc7a6">](https://www.pololu.com/product/1561)


## Usage

- Upload the code in `RoverController` to the Arduino board 
- Create a ROS workspace and add the contents of this repo to the `src` folder

```
thumper_ws/
.... build/
.... devel/
.... src/
....... wild-thumper/
```

Then launch

```
catkin_make
source devel/setup.bash
roslaunch pololu pololu_teleop.launch
```

Use `w`, `a`, `s`, `d` to control the robot.

The Arduino interface was adapted from: [https://github.com/watai/Robotic-Photographer](https://github.com/watai/Robotic-Photographer)

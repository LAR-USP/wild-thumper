# Pololu Dagu Wild-Thumper 6WD

[<img src="https://a.pololu-files.com/picture/0J2312.600x480.jpg?a343d9a91106a34914708601bcadc7a6">](https://www.pololu.com/product/1561)

## ROS Mode

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

## RC Mode

Connect the RC receiver to the TReX RMC

[<img src="https://a.pololu-files.com/picture/0J94.1200.jpg?43096159ac9239ee1952321fbcbcb829">](https://www.pololu.com/product/1561)

Make sure you connected the BEC Jumper to give power to the RC receiver

[<img src="https://a.pololu-files.com/picture/0J292.1200.jpg?a3184d5a05415a51168b401d4b8207df">](https://www.pololu.com/product/1561)

To calibrate the RC controller, read section `3.e` of the manual

https://www.pololu.com/docs/pdf/0J1/TReX.pdf

The board has 2 status LEDs (red and green) and one power LED (blue). Use them to debug according to the descriptions provided in the manual.

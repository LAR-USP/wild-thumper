#!/usr/bin/env python

from __future__ import print_function

import rospy
from std_msgs.msg import Int32

import sys, select, termios, tty

publisher = rospy.Publisher('pololu/move', Int32, queue_size = 1)


def getKey(key_timeout):
    tty.setraw(sys.stdin.fileno())
    rlist, _, _ = select.select([sys.stdin], [], [], key_timeout)
    if rlist:
        key = sys.stdin.read(1)
    else:
        key = ''
    termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
    return key


def vels(speed, turn):
    return "currently:\tspeed %s\tturn %s " % (speed,turn)

if __name__=="__main__":
    settings = termios.tcgetattr(sys.stdin)

    rospy.init_node('teleop')

    key_timeout = None

    try:
        while(1):
            key = getKey(key_timeout)
            print(key)
            if key == 'w':
                publisher.publish(0)
            elif key == 'a':
                publisher.publish(2)
            elif key == 's':
                publisher.publish(3)
            elif key == 'd':
                publisher.publish(1)
            elif key == ' ':
                publisher.publish(4)
            else:
                break

    except Exception as e:
        print(e)

    finally:
        termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)

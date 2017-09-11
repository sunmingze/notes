#!/usr/bin python3
# coding: utf-8

"""
AUTHOR: bovenson
EMAIL: szhkai@qq.com
FILE: emq-send.py
DATE: 17-8-25 下午4:31
DESC: 
"""
from time import sleep

import paho.mqtt.client as mqtt

client = mqtt.Client()

client.connect("localhost", 1883, 60)

for i in range(10):
    print(client.publish('/test', payload='Hello World %d' % i))
    sleep(1)
#!/usr/bin/python

import sys
import time
import Adafruit_DHT
import datetime
import RPi.GPIO as GPIO

sensor=Adafruit_DHT.DHT22
sensorPin=17
ledPin=13

def setup():
    GPIO.setmode(GPIO.BOARD)       # Numbers GPIOs by physical location
    GPIO.setup(ledPin, GPIO.OUT)   # Set ledPin's mode is output
    GPIO.output(ledPin, GPIO.LOW) # Set ledPin low to off led

def destroy():
    GPIO.output(ledPin, GPIO.LOW)     # led off
    GPIO.cleanup()                     # Release resource

def ledOn():
    GPIO.output(ledPin, GPIO.HIGH)
    
def ledOff():
    GPIO.output(ledPin, GPIO.LOW)

def readSensors():
    # Try to grab a sensor reading.  Use the read_retry method which will retry up
    # to 15 times to get a sensor reading (waiting 2 seconds between each retry).
    humidity, temperature = Adafruit_DHT.read_retry(sensor, sensorPin)

    # Note that sometimes you won't get a reading and
    # the results will be null (because Linux can't
    # guarantee the timing of calls to read the sensor).
    # If this happens try again!
    if humidity is not None and temperature is not None:
        return temperature,humidity
    else:
        return 0,0
    

setup()

try:
    while True:
        temperature,humidity = readSensors()
        print('{0:%Y-%m-%d %X},{1:0.1f},{2:0.1f}'.format(datetime.datetime.now(), temperature, humidity))
        if humidity>=60:
            ledOn()
        else:
            ledOff()
            
        sys.stdout.flush()
        time.sleep(1)
except KeyboardInterrupt:  # When 'Ctrl+C' is pressed, the child program destroy() will be  executed.
    destroy()

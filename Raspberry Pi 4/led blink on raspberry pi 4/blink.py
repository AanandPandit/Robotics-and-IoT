import RPi.GPIO as GPIO
import time

# connect led pin to GPIO 26
led = 26

# setup gpio
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(led,GPIO.OUT)

# run program 
while True:
    GPIO.output(led,GPIO.HIGH)
    print("led is on")
    time.sleep(1)
    GPIO.output(led,GPIO.LOW)
    print("led is off")
    time.sleep(1)

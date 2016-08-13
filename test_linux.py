from arduino_interface import ArduinoInterface
from time import sleep

def print_thing(thing):
    print(thing)

ard = ArduinoInterface()
ard.connect()
ard.start_listening()
sleep(1)
ard.signal.connect(print_thing)
sleep(1)
ard.go_left()
ard.go_left()
ard.go_right()
while True:
    sleep(1)

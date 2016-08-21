import serial
from time import sleep
import threading
from blinker import signal
import sys
import struct
from enum import Enum

GO_LEFT = 0
GO_BACK = 1
GO_FORWARD = 2
GO_RIGHT = 3
STOP = 4
VEL_DOWN = 5
VEL_UP = 6

class ArduinoInterface():
    def __init__(self, port='/dev/ttyACM0',baud=38400):
        self.port = port
        self.baud = baud
        self.listen_thread = None
        self.signal = signal('listen_signal')
        self.lock = threading.Lock()
    
    def connect(self):
        self.serial = serial.Serial(self.port,self.baud,write_timeout=0)
    
    def disconnect(self):
        self.serial.close()
    
    def send(self,message):
        byte_mess = struct.pack("B",message)
        self.serial.write(byte_mess)
    
    def go_left(self):
        self.send(GO_LEFT)
        
    def go_back(self):
        self.send(GO_BACK)
    
    def go_forward(self):
        self.send(GO_FORWARD)

    def go_right(self):
        self.send(GO_RIGHT)
    
    def stop(self):
        self.send(STOP)
    
    def vel_down(self):
        self.send(VEL_DOWN)

    def vel_up(self):
        self.send(VEL_UP)

    def _listen(self):
        with self.lock:
            while True:
                line = self.serial.readline()
                #sys.stdout.flush()
                self.signal.send(line)
                sleep(.01)
    
    def start_listening(self):
        self.listen_thread = threading.Thread(target = self._listen)
        self.listen_thread.daemon = True
        self.listen_thread.start()

    def stop_listening(self):
        self.listen_thread.join()
        self.listen_thread = None

import serial
from time import sleep
import threading
from blinker import signal
import sys
import struct

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
        self.send(0)
        
    def go_down(self):
        self.send(1)
    
    def go_up(self):
        self.send(2)

    def go_right(self):
        self.send(3)

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

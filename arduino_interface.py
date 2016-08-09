import serial
from time import sleep
import threading
from blinker import signal

class ArduinoInterface():
    def __init__(self, port='/dev/ttyACM0',baud=9600):
        self.port = port
        self.baud = baud
        self.listen_thread = None
        self.signal = None
    
    def connect(self):
        self.serial = serial.Serial(self.port,self.baud)
    
    def disconnect(self):
        self.serial.close()
    
    def send(self,message):
        self.signal.write(message)
    
    def go_left(self):
        self.send('l')

    def go_right(self):
        self.send('r')

    def start_listening(self):
        self.listen_thread = threading.Thread(target = _listen)
        self.listen_thread.start()

    def stop_listening(self):
        self.listen_thread.join()
        self.listen_thread = None

    def _listen(self):
        if self.listen_thread is not None:
            return
        self.signal = signal('listen_signal')
        while True:
            line = self.serial.readline()
            print line
            self.signal.send(line)
            sleep(.1)

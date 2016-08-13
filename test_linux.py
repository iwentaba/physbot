import curses
from arduino_interface import ArduinoInterface
from time import sleep

def init_curses():
    stdscr = curses.initscr()
    curses.cbreak() # use cbreak to not require a return key press
    curses.noecho() # prevent keystroke echo
    return stdscr
    
def init_arduino():
    ard = ArduinoInterface()
    ard.connect()
    ard.start_listening()
    sleep(1)
    ard.signal.connect(print_thing)
    return ard

def print_thing(thing):
    print('Serial:{}\r'.format(thing.decode()))

stdscr = init_curses()
ard = init_arduino()

print("press q to quit\r")

while True:
    c = stdscr.getch()
    keystr = chr(c)
    if keystr=="q": 
        break
    elif keystr=='h':
        print('left\r')
        ard.go_left()
    elif keystr=='j':
        print('down\r')
        ard.go_down()
    elif keystr=='k':
        print('up\r')
        ard.go_up()
    elif keystr=='l':
        print('right\r')
        ard.go_right()
    sleep(0.01)
 
curses.endwin()

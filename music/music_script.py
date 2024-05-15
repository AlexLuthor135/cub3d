import os
import sys
import pygame

with open('pid.txt', 'w') as f:
    f.write(str(os.getpid()))  # Write the PID of the Python script

pygame.mixer.init()
pygame.mixer.music.load(sys.argv[1])
pygame.mixer.music.play()
try:
    while pygame.mixer.music.get_busy() == True:
        continue
except KeyboardInterrupt:
    print("\nMusic stopped by user")

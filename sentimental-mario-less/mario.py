# TODO
from cs50 import get_int
height = 0

while height < 1 or height > 8:
    height = get_int("height: ")

for i in range(height):
    for spaces in range(height-i-1):
        print(" ", end="")
    j = 0
    while j <= i:
        print("#", end="")
        j +=1
    print("")
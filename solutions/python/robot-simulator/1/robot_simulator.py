""" Module simulates a robot """
# Globals for the directions
# Change the values as you see fit
EAST = (1, 0)
NORTH = (0, 1)
WEST = (-1, 0)
SOUTH = (0, -1)

directions = [NORTH, EAST, SOUTH, WEST]

class Robot:
    """ A class to simulate a robot """
    def __init__(self, direction=NORTH, x_pos=0, y_pos=0):
        """ class contructor """
        self.direction = direction
        self.coordinates = (x_pos, y_pos)

    def move(self, instuctions):
        """ Move function to turn and advance the robot"""
        for ins in instuctions:
            if ins == "R":
                dir_index = directions.index(self.direction) + 1
                if dir_index >= 4:
                    dir_index = 0
                self.direction = directions[dir_index]
            if ins == "L":
                dir_index = directions.index(self.direction) - 1
                if dir_index < 0:
                    dir_index = 3
                self.direction = directions[dir_index]
            if ins == "A":
                self.coordinates = (self.coordinates[0] + self.direction[0],
                                    self.coordinates[1] + self.direction[1])



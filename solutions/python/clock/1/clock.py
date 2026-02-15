""" Module docstring"""
class Clock:
    """ Class docstring"""
    def __init__(self, hour, minute):
        self.hour = (hour + minute // 60) % 24
        self.minute = minute % 60


    def __repr__(self):
        return "Clock({0}, {1})".format(self.hour, self.minute)

    def __str__(self):
        return "{0:02d}:{1:02d}".format(self.hour, self.minute)

    def __eq__(self, other):
        if self.hour == other.hour and self.minute == other.minute:
            return True
        return False

    def __add__(self, minutes):
        self.minute += minutes
        return Clock(self.hour, self.minute)

    def __sub__(self, minutes):
        self.minute -= minutes
        return Clock(self.hour, self.minute)

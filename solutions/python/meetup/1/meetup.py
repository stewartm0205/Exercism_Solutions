""" Module docstring """
from datetime import date
# subclassing the built-in ValueError to create MeetupDayException
class MeetupDayException(ValueError):
    """Exception raised when the Meetup weekday and count do not result in a valid date.

    message: explanation of the error.

    """
    def __init__(self, message):
        self.message = message


def meetup(year, month, week, day_of_week):
    """ Function docstring"""
    if month in [1, 3, 5, 7, 8, 10, 12]:
        last_day_of_month = 31
    elif month == 2:
        if year % 4 == 0:
            last_day_of_month = 29
        else:
            last_day_of_month = 28
    else:
        last_day_of_month = 30

    dow_count = 0
    wom = ["", "first", "second", "third", "fourth", "fifth"]
    for day in range(1, last_day_of_month+1):
        d = date(year, month, day)
        dow = d.strftime('%A')
        if dow == day_of_week:
            dow_count += 1
            last = day
            if week == "teenth" and  day >= 13 and day <= 19:
                return date(year, month, day)
            if week == wom[dow_count]:
                return date(year, month, day)
    if week == "last":
        return date(year, month, last)
    raise MeetupDayException("That day does not exist.")

"""Solution to Ellen's Alien Game exercise."""


class Alien:
    """Create an Alien object with location x_coordinate and y_coordinate.

    Attributes
    ----------
    (class)total_aliens_created: int
    x_coordinate: int - Position on the x-axis.
    y_coordinate: int - Position on the y-axis.
    health: int - Amount of health points.

    Methods
    -------
    hit(): Decrement Alien health by one point.
    is_alive(): Return a boolean for if Alien is alive (if health is > 0).
    teleport(new_x_coordinate, new_y_coordinate): Move Alien object to new coordinates.
    collision_detection(other): Implementation TBD.
    """
    total_aliens_created = 0

    def __init__(self, x_coordinate, y_coordinate):
        self.x_coordinate = x_coordinate
        self.y_coordinate = y_coordinate
        self.health = 3
        self.__class__.total_aliens_created += 1

    def hit(self):
        """Decrements health whenever called """
        self.health -= 1

    def is_alive(self):
        """Check if Alien is still alive by checking value of Health """
        if self.health > 0:
            return True
        return False

    def teleport(self, new_x_coordinate, new_y_coordinate):
        """Move the Alien to a new corrdiante """
        self.x_coordinate = new_x_coordinate
        self.y_coordinate = new_y_coordinate

    def collision_detection(self, other):
        """To be written """
        #msg = "error"


def new_aliens_collection(positions):
    """Created a list of aliens given a set of coordiantes
    Parameter:
    positions (list of tuples): list of coordiantes tuples:
    Returns:
    list of aliens
    """

    aliens = []
    for alien_position in positions:
        aliens.append(Alien(alien_position[0], alien_position[1]))
    return aliens

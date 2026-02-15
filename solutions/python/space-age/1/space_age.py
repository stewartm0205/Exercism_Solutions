class SpaceAge(object):
    def __init__(self, seconds):
        self.seconds = seconds
        self.earth_year = 31557600 

    def on_mercury(self):
        return round((self.seconds/self.earth_year) / 0.2408467,2)

    def on_venus(self):
        return round((self.seconds/self.earth_year) / 0.61519726,2)

    def on_earth(self):
        return round(self.seconds/self.earth_year,2)

    def on_mars(self):
        return round((self.seconds/self.earth_year) / 1.880815,2)

    def on_jupiter(self):
        return round((self.seconds/self.earth_year) / 11.86261,2)

    def on_saturn(self):
        return round((self.seconds/self.earth_year) / 29.44749,2)

    def on_uranus(self):
        return round((self.seconds/self.earth_year) / 84.016846,2)

    def on_neptune(self):
        return round((self.seconds/self.earth_year) / 164.7913,2)


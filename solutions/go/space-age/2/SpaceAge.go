// Package space Determine how old you are in the years of a specific planet years.
package space

// Age return how many planet years you are for the seconds passed and the planet passed as arguments.
func Age(seconds float64, planet string) float64 {
  ey := seconds / 31557600.0 
	if planet == "Earth" {
		return ey
	}
	if planet == "Mercury" {
		return ey / 0.2408467
	}
	if planet == "Venus" {
		return ey / 0.61519726
	}
	if planet == "Mars" {
		return ey / 1.8808158
	}
	if planet == "Jupiter" {
		return ey / 11.862615
	}
	if planet == "Saturn" {
		return ey / 29.447498
	}
	if planet == "Uranus" {
		return ey / 84.016846
	}
	if planet == "Neptune" {
		return ey / 164.79132
	}
	return 0
}

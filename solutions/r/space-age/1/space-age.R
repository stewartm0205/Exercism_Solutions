space_age <- function(seconds, planet) {
planets <- c("earth", "mercury", "venus", "mars", "jupiter", "saturn", "uranus", "neptune")
p <- which(planets == planet)
eyears <- c(1.0000000, 0.2408467, 0.61519726, 1.8808158, 11.862615, 29.447498, 84.016846, 164.79132)
return (round(seconds / 31557600 / eyears [p],2))
}

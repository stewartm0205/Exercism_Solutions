package raindrops

import "strconv"

// Convert - changes a number into raindrops
func Convert(n int) string {
    var rd string 
    if n % 3 == 0 { rd += "Pling"}
    if n % 5 == 0 { rd += "Plang"}
    if n % 7 == 0 { rd += "Plong"}
    if rd == "" { rd = strconv.Itoa(n)}
    return rd
}

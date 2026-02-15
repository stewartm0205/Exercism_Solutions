package raindrops

import "strconv"

// Convert - changes a number into raindrops
func Convert(n int) string {
    var rd string = ""
    if n % 3 == 0 { rd = rd + "Pling"}
    if n % 5 == 0 { rd = rd + "Plang"}
    if n % 7 == 0 { rd = rd + "Plong"}
    if rd == "" { rd = strconv.FormatInt(int64(n), 10)}
    return rd
}

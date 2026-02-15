package scrabble

func Score(word string) int {

	var s int
	for i := range word {
		switch word[i] {
		case 'a', 'e', 'i', 'o', 'u', 'l', 'n', 'r', 's', 't',
		 'A', 'E', 'I', 'O', 'U', 'L', 'N', 'R', 'S', 'T':
			s++
		case 'd', 'g', 'D', 'G':
			s += 2
		case 'b', 'c', 'm', 'p', 'B', 'C', 'M', 'P':
			s += 3
		case 'f', 'h', 'v', 'w', 'y', 'F', 'H', 'V', 'W', 'Y':
			s += 4
		case 'k', 'K':
			s += 5
		case 'j', 'x', 'J', 'X':
			s += 8
		case 'q', 'z', 'Q', 'Z':
			s += 10
		}
	}
	return s

}

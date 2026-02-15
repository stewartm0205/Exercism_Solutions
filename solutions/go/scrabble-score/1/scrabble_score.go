package scrabble
import "strings"

func Score(word string) (int) {
	
  var lcw = strings.ToLower(word) 
	var s int = 0;
	for i := range lcw {
	  switch lcw[i] {
    case 'a','e','i','o','u','l','n','r','s','t':
			s++;
    case 'd','g':
			s += 2;
    case 'b','c','m','p':
			s += 3;
    case 'f','h','v','w','y':
			s += 4;
    case 'k':
			s += 5;
    case 'j','x':
			s += 8;
    case 'q','z':
			s += 10;
		}
	}
	return s

}

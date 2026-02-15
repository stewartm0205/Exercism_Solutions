package hamming

import "errors"

func Distance(a, b string) (int, error) {
	
	var d int = 0;
	if len(a) == len(b) {
		for i := 0; i<len(a); i++ {
			if a[i:i+1] != b[i:i+1] {
				d++;
			}
		}
		return d, nil
	} else {
		return 0, errors.New("bad arguments")
	}
}

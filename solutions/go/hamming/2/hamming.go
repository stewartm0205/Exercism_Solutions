package hamming

import "errors"

func Distance(a, b string) (int, error) {
	
	var d int = 0;
	if len(a) != len(b) {	
		return 0, errors.New("bad arguments")
	}
	for i, _ := range a {
		if a[i] != b[i] {
			d++;
		}
	}
	return d, nil

}

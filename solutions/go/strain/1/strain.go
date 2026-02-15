package strain

type Ints []int
type Lists [][]int
type Strings []string

func (i Ints) Keep(filter func(int) bool) Ints {
	var keepInts []int;
	for _, n := range i {
		if filter(n) {
			keepInts = append(keepInts, n)
		}
	}
	return keepInts
}

func (i Ints) Discard(filter func(int) bool) Ints {
	var keepInts []int;
	for _, n := range i {
		if !filter(n) {
			keepInts = append(keepInts, n)
		}
	}
	return keepInts
}

func (l Lists) Keep(filter func([]int) bool) Lists {
	var keepLists Lists;
	for _, le := range l {
		if filter(le) {
			keepLists = append(keepLists, le)
		}
	}
	return keepLists
}

func (s Strings) Keep(filter func(string) bool) Strings {
	var keepStrings Strings;
	for _, se := range s {
		if filter(se) {
			keepStrings = append(keepStrings, se)
		}
	}
	return keepStrings
}

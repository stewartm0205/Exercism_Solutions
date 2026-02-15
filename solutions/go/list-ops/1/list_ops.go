package listops

// IntList is an abstraction of a list of integers which we can define methods on
type IntList []int

func (s IntList) Foldl(fn func(int, int) int, initial int) int {
	var r int = initial
	for _, v := range s {
		r = fn(r, v)
	}
	return r
}

func (s IntList) Foldr(fn func(int, int) int, initial int) int {
	var r int = initial
	for i:=len(s)-1;i>=0; i-- {
		r = fn (s[i], r)
	}
	return r
}

func (s IntList) Filter(fn func(int) bool) IntList {
	var r IntList = IntList{}
	for _, v := range s {
		if fn(v) {
			r = append(r,v)
		}
	}
	return r
}

func (s IntList) Length() int {
	return len(s)
}

func (s IntList) Map(fn func(int) int) IntList {
	var r IntList = IntList{}
	for _, v := range s {
		r = append(r,fn(v))
	}
	return r
}

func (s IntList) Reverse() IntList {
	var r IntList = IntList{}
	for i:=len(s)-1;i>=0; i-- {
		r = append(r,s[i])
	}
	return r
}

func (s IntList) Append(lst IntList) IntList {
	var r IntList = IntList {}
	r = s
	r = append(s, lst...)
	return r
}

func (s IntList) Concat(lists []IntList) IntList {
	var r IntList = s
	for _,l := range lists {
			r = append(r, l...)
	}
	return r
}
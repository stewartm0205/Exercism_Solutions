// Package that searchs a file for a string and prints the line
package grep

import (
"os"
"bufio"
"strings"
"strconv"
)

// function that searches files for a string and print lines
func Search(pattern string, flags, files []string) []string {
	//fmt.Println("pattern=",pattern,"flags=",flags,"files=",files)
	var linenum bool = false
	var fileonly bool = false
	var nocase bool = false
	var invert bool = false
	var fullline = false

	for _,flag := range flags {
		switch flag {
		case "-n":
			linenum = true
		case "-l":
			fileonly = true
		case "-i":
			nocase = true
		case "-v":
			invert = true
		case "-x":
			fullline = true
		}

	}
	var lines []string = []string{}
	var ln int
	var match bool
	var upattern, uline string
	for _,file := range files {
		f,err := os.Open(file)
		if err != nil {
			panic("file error")
		}
		defer f.Close()
		scanner := bufio.NewScanner(f)
		ln = 0
		for scanner.Scan() {
			line := scanner.Text()
			ln++
			//fmt.Println("line=",line)
			match = false
			if nocase {
				upattern = strings.ToUpper(pattern)
				uline = strings.ToUpper(line)
				if (!fullline && strings.Index(uline,upattern)>=0) ||
				(fullline && uline == upattern) {
					match = true
				}
			} else {
				if (!fullline && strings.Index(line,pattern)>=0) ||
				   (fullline && line == pattern) {
					match = true
				}
			}
			if (match && !invert) || (!match && invert) {
				if fileonly {
					var already bool = false
					for _,f := range lines {
						if f == file {
							already = true
						}
					}
					if !already {
						lines = append(lines,file)
					}
				} else {
					if linenum {
						if len(files)>1 {
							lines = append(lines,file+":"+strconv.Itoa(ln)+":"+line)
						} else {
							lines = append(lines,strconv.Itoa(ln)+":"+line)
						}
					} else {
						if len(files)>1 {
							lines = append(lines,file+":"+line)
						} else {
							lines = append(lines,line)
						}
					}
				}

			}
		}
	}
	return lines
}

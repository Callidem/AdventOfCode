package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	file, err := os.Open("data.txt")
	if err != nil {
		fmt.Println("Erro ao abrir o arquivo:", err)
		return
	}
	defer file.Close()
	arq := bufio.NewReader(file)
	const trace = '-'
	const comma = ','
	lineLen := 0
	totalSum := 0
	for {
		line, err := arq.ReadString(trace)
		if len(line) > 0 {
			fmt.Printf("Readline: %q\n", line)
		} else {
			break
		}
		if line[len(line)-1] == comma || line[len(line)-1] == trace {
			lineLen = len(line) - 1
		} else {
			lineLen = len(line)
		}

		n1, err := strconv.Atoi(string(line[0:lineLen]))
		fmt.Printf("%d\n", n1)

		line, err = arq.ReadString(comma)
		if line[len(line)-1] == comma || line[len(line)-1] == trace {
			lineLen = len(line) - 1
		} else {
			lineLen = len(line)
		}
		n2, err := strconv.Atoi(string(line[0:lineLen]))
		fmt.Printf("%d\n", n2)
		for i := n1; i <= n2; i++ {
			s1 := strconv.Itoa(i)
			//fmt.Printf("Number: %s\n", s1)
			h1 := "a"
			if len(s1) > 2 {
				h1 = s1[0:(len(s1) / 2)]
				//fmt.Printf("Vai até %d\n", (len(s1) / 2))
			} else {
				h1 = s1[0 : len(s1)-1]
			}
			h2 := s1[(len(s1) / 2):]
			//fmt.Printf("H1: %s H2: %s\n", h1, h2)
			if h1 == h2 {
				totalSum += i
				//fmt.Printf("ACHEI IGUAL: %d\n", i)
			}
		}
		if err != nil {
			break
		}
	}
	fmt.Printf("Total Sum: %d\n", totalSum)
}

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
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
	interval := "abc"
	for {
		line, err := arq.ReadString(trace)
		interval = line
		if len(line) > 0 {
			//fmt.Printf("Readline: %q\n", line)
		} else {
			break
		}
		if line[len(line)-1] == comma || line[len(line)-1] == trace {
			lineLen = len(line) - 1
		} else {
			lineLen = len(line)
		}

		n1, err := strconv.Atoi(string(line[0:lineLen]))

		line, err = arq.ReadString(comma)
		interval += line
		fmt.Printf("Interval: %s\n", interval)
		if line[len(line)-1] == comma || line[len(line)-1] == trace {
			lineLen = len(line) - 1
		} else {
			lineLen = len(line)
		}
		n2, err := strconv.Atoi(string(line[0:lineLen]))
		//ideia: pegar o primeiro caractere e comparar suas aparições para identificar um padrão
		// mais facil: testar com substrings de tamanho 2, 3, 4... ate metade do tamanho da string
		for i := n1; i <= n2; i++ {
			s1 := strconv.Itoa(i)
			// Detect true repeated substrings: length < len(s1) and repeats >= 2
			found := false
			for subLen := 1; subLen <= len(s1)/2; subLen++ {
				if len(s1)%subLen != 0 {
					continue
				}
				repeatCount := len(s1) / subLen
				if repeatCount < 2 {
					continue
				}
				substr := s1[0:subLen]
				repeated := strings.Repeat(substr, repeatCount)
				if repeated == s1 {
					fmt.Printf("Found repeated substring: %s in number: %s\n", substr, s1)
					totalSum += i
					found = true
					break
				}
			}
			_ = found
		}
		if err != nil {
			break
		}
	}
	fmt.Printf("Total Sum: %d\n", totalSum)
}

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	file, err := os.Open("example.txt")
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
		//ideia: pegar o primeiro caractere e comparar suas apari;'oes para identificar um padr'ao

		for i := n1; i <= n2; i++ {
			s1 := strconv.Itoa(i)
			//fmt.Printf("Number: %s\n", s1)
			char := s1[0]
			patternFound := false
			for j := 1; j < len(s1) && !patternFound; j++ {
				if s1[j] == char {
					index := strings.Index(s1[j:], string(char))
					if index != -1 {
						padrao := s1[0 : j+index]
						fmt.Printf("Substring do possivel padrao: %s, j+index= %d\n", padrao, j+index)

						for k := 0; k <= len(s1)-1; k += len(padrao) {
							if k == len(s1) {
								totalSum += i
								patternFound = true
								fmt.Printf("Padrao encontrado: %s no numero %s\n", padrao, s1)
								break
							}
							if strings.Index(s1[k:], padrao) != 0 {
								break
							}

						}
					}
					fmt.Printf("String: %s, Char: %c, j: %d, Index: %d\n", s1, char, j, index+j)
				}
			}
		}
		if err != nil {
			break
		}
	}
	fmt.Printf("Total Sum: %d\n", totalSum)
}

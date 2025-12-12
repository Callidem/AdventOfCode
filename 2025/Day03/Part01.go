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
	totalSum := 0
	for {
		line, _, err := arq.ReadLine()
		if len(line) > 0 {
			fmt.Printf("Readline: %q\n", line)
		} else {
			break
		}
		max := 0
		joltage := 0
		sJoltage := "abc"
		// achar caractere das dezenas
		indexDezenas := 0
		for i := 0; i < len(line)-1; i++ {
			aux, err := strconv.Atoi(string(line[i]))
			if err != nil {
				break
			}
			if aux > max {
				max = aux
				indexDezenas = i
			}
		}
		sJoltage = strconv.Itoa(max)
		//achar caractere das unidades
		unidades := indexDezenas + 1
		for max = 0; unidades < len(line); unidades++ {
			aux, err := strconv.Atoi(string(line[unidades]))
			if err != nil {
				break
			}
			if aux > max {
				max = aux
			}
		}
		sJoltage += strconv.Itoa(max)
		joltage, err = strconv.Atoi(sJoltage)
		fmt.Printf("Joltage: %d\n", joltage)
		totalSum += joltage
		if err != nil {
			break
		}
	}
	fmt.Printf("Total Sum: %d\n", totalSum)
}

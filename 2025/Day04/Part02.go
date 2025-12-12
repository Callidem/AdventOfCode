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
		sJoltage := ""
		// achar caractere das dezenas
		index := 0
		sJoltageLen := 12
		limit := len(line) - (sJoltageLen - 1)
		for j := 0; j < sJoltageLen; j++ {
			max = 0
			fmt.Printf("Analisando casa %d do joltage\n", j)
			for i := index; i < limit; i++ {
				fmt.Printf("Analisando indice %d, valor: %q\n", i, line[i])
				aux, err := strconv.Atoi(string(line[i]))
				if err != nil {
					break
				}
				if aux > max {
					fmt.Printf("Novo maior encontrado para o indice %d: %d\n", i, aux)
					max = aux
					index = i + 1
					fmt.Printf("Indice novo: %d\n", index)

				}
			}
			limit++
			fmt.Printf("Limite novo: %d\n", limit)
			sJoltage += strconv.Itoa(max)
		}
		joltage, err = strconv.Atoi(sJoltage)
		fmt.Printf("Joltage: %d\n", joltage)
		totalSum += joltage
		if err != nil {
			break
		}
	}
	fmt.Printf("Total Sum: %d\n", totalSum)
}

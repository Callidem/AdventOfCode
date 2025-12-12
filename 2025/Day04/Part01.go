package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	file, err := os.Open("data.txt")
	if err != nil {
		fmt.Println("Erro ao abrir o arquivo:", err)
		return
	}
	defer file.Close()
	arq := bufio.NewReader(file)
	var mapa []string
	var adjSum [][]int

	totalSum := 0
	for {
		line, _, err := arq.ReadLine()
		if len(line) > 0 {
			//fmt.Printf("Readline: %q\n", line)
			mapa = append(mapa, string(line))
			adjSum = append(adjSum, make([]int, len(line)))
		} else {
			break
		}
		if err != nil {
			break
		}
	}

	for i := 0; i < len(mapa); i++ {
		//fmt.Printf("Linha %d: %s\n", i, mapa[i])
		for j := 0; j < len(mapa[i]); j++ {
			if i > 0 {
				if mapa[i-1][j] == '@' {
					adjSum[i][j]++
				}
				if j > 0 {
					if mapa[i-1][j-1] == '@' {
						adjSum[i][j]++
					}
				}
				if j < len(mapa[i])-1 {
					if mapa[i-1][j+1] == '@' {
						adjSum[i][j]++
					}
				}
			}
			if i < len(mapa)-1 {
				if mapa[i+1][j] == '@' {
					adjSum[i][j]++
				}
				if j < len(mapa[i])-1 {
					if mapa[i+1][j+1] == '@' {
						adjSum[i][j]++
					}
				}
				if j > 0 {
					if mapa[i+1][j-1] == '@' {
						adjSum[i][j]++
					}
				}
			}
			if j > 0 {
				if mapa[i][j-1] == '@' {
					adjSum[i][j]++
				}
			}
			if j < len(mapa[i])-1 {
				if mapa[i][j+1] == '@' {
					adjSum[i][j]++
				}
			}
		}
	}
	for i := 0; i < len(adjSum); i++ {
		for j := 0; j < len(adjSum[i]); j++ {

			if adjSum[i][j] < 4 && mapa[i][j] != '.' {
				//fmt.Printf("i:%d, j:%d, valor eh menor que 4 e caractere eh @\n", i, j)
				totalSum++
				//fmt.Printf(" %d ", adjSum[i][j])
			} else {
				//fmt.Printf(" . ")
			}
		}
		//fmt.Printf("\n")
	}

	fmt.Printf("Total Sum: %d\n", totalSum)
}

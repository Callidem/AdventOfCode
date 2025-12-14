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
		fmt.Println("1Erro ao abrir o arquivo:", err)
		return
	}
	defer file.Close()
	arq := bufio.NewReader(file)
	mapa := make(map[int]int)

	line, _, err := arq.ReadLine()
	if err != nil {
		fmt.Println("2.0Erro ao ler o arquivo:", err)
		return
	}
	if len(line) < 1 {
		return
	}
	//fmt.Printf("%s\n", string(line))
	interval := strings.Split(string(line), "-")
	n1, err := strconv.Atoi(interval[0])

	if err != nil {
		fmt.Println("2.1Erro ao ler o arquivo:", err)
		return
	}
	//fmt.Printf("n1:%d\n", n1)

	n2, err := strconv.Atoi(interval[1])
	if err != nil {
		fmt.Println("2.2Erro ao ler o arquivo:", err)
		return
	}
	mapa[n1] = n2
	fmt.Printf("Adicionado intervalo %d-%d\n", n1, n2)

	for {
		line, _, err := arq.ReadLine()
		if err != nil {
			fmt.Println("2.0Erro ao ler o arquivo:", err)
			break
		}
		if len(line) < 1 {
			break
		}
		//fmt.Printf("%s\n", string(line))
		interval := strings.Split(string(line), "-")
		n1, err := strconv.Atoi(interval[0])

		if err != nil {
			fmt.Println("2.1Erro ao ler o arquivo:", err)
			break
		}
		//fmt.Printf("n1:%d\n", n1)

		n2, err := strconv.Atoi(interval[1])
		if err != nil {
			fmt.Println("2.2Erro ao ler o arquivo:", err)
			break
		}
		fmt.Printf("Processando intervalo %d-%d\n", n1, n2)
		for min, max := range mapa {
			fmt.Printf("  Comparando com intervalo %d-%d\n", min, max)
			if n1 >= min && n1 <= max {
				if n2 > max {
					fmt.Printf("Atualizando intervalo %d-%d para %d-%d\n", min, max, min, n2)
					n1 = min
					delete(mapa, min)
				}
			}
			if n2 >= min && n2 <= max {
				if n1 < min {
					fmt.Printf("Atualizando intervalo %d-%d para %d-%d\n", min, max, n1, max)
					n2 = max
					delete(mapa, min)
				}
			} else if n1 < min && n2 > max {
				fmt.Printf("Removendo intervalo %d-%d por estar contido em %d-%d\n", min, max, n1, n2)
				delete(mapa, min)
			}
			mapa[n1] = n2
		}

	}
	alterations := true
	for alterations {
		alterations = false
		for n1, n2 := range mapa {
			fmt.Printf("Reavaliando intervalo %d-%d\n", n1, n2)
			for min, max := range mapa {
				fmt.Printf("  Comparando com intervalo %d-%d\n", min, max)
				if n1 >= min && n1 <= max {
					if n2 > max {
						fmt.Printf("Atualizando intervalo %d-%d para %d-%d\n", min, max, min, n2)
						n1 = min
						alterations = true
						delete(mapa, min)
					}
				}
				if n2 >= min && n2 <= max {
					if n1 < min {
						fmt.Printf("Atualizando intervalo %d-%d para %d-%d\n", min, max, n1, max)
						n2 = max
						alterations = true
						delete(mapa, min)
					}
				} else if n1 < min && n2 > max {
					fmt.Printf("Removendo intervalo %d-%d por estar contido em %d-%d\n", min, max, n1, n2)
					alterations = true
					delete(mapa, min)
				}
				mapa[n1] = n2
			}
		}
	}
	totalIngs := 0
	fmt.Printf("Intervalos: %d\n", len(mapa))
	for min, max := range mapa {
		fmt.Printf("  Intervalo final %d-%d\n", min, max)
		totalIngs += (max - min + 1)
	}
	fmt.Printf("Total de ingredientes: %d\n", totalIngs)
}

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
	fresh := 0
	rotten := 0

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
		if _, ok := mapa[n1]; ok {
			if mapa[n1] < n2 {
				mapa[n1] = n2
			}
		} else {
			mapa[n1] = n2
		}

		//fmt.Printf("n2:%d\n", n2)
		fmt.Printf("Mapa[%d]=%d\n", n1, mapa[n1])
	}
	fmt.Printf("Intervalos: %d\n", len(mapa))
	for {
		line, _, err := arq.ReadLine()
		if len(line) < 1 {
			break
		}
		//fmt.Printf("%s\n", string(line))
		ing, err := strconv.Atoi(string(line))
		if err != nil {
			fmt.Println("3Erro ao ler o arquivo:", err)
			break
		}
		fresco := false
		//fmt.Printf("ing: %d\n", ing)
		for min, max := range mapa {
			if ing >= min && ing <= max {
				//fmt.Printf("%d fresh in range: %d-%d\n", ing, min, max)
				fresh++
				fresco = true
				break
			} else {
				//fmt.Printf("%d not in range: %d-%d\n", ing, min, max)
			}
		}
		if fresco == false {
			//fmt.Printf("%d nao esta fresco\n", ing)
			rotten++
		}
	}
	fmt.Printf("Total de ingredientes frescos: %d\n", fresh)
	fmt.Printf("Total de ingredientes podres: %d\n", rotten)
}

package main

import (
	"crypto/sha512"
	"fmt"
	"golang.org/x/crypto/pbkdf2"
)

func get_big(que []byte) string {
	// Get a big password
	result := ""

	for i := 0; i < 21; i++ {
		result += lower()[int(que[i])]
	}

	//Add special, upper and number
	result += special()[int(que[21])]
	result += upper()[int(que[22])]
	result += numbers()[int(que[23])]

	return result
}

func get_small(que []byte) string {
	// Get a small password
	result := ""

	for i := 0; i < 9; i++ {
		result += lower()[int(que[i])]
	}

	//Add special, upper and number
	result += special()[int(que[9])]
	result += upper()[int(que[10])]
	result += numbers()[int(que[11])]

	return result
}

func get_passphrase(que []byte) string {
	// Get a 7 word passphrase
	result := ""

	for i := 0; i < 7; i++ {
		result += words()[int(que[i])]
	}

	//Add special, upper and number
	result += special()[int(que[7])]
	result += upper()[int(que[8])]
	result += numbers()[int(que[9])]

	return result
}

func main() {
	dk := pbkdf2.Key([]byte("The sentence."), []byte("word"), 32768, 64, sha512.New)
	fmt.Printf("%v \n", dk)
	fmt.Printf("%x \n", dk)

	big := get_big(dk)
	small := get_small(dk)
	phrase := get_passphrase(dk)

	fmt.Printf("%v \n", big)
	fmt.Printf("%v \n", small)
	fmt.Printf("%v \n", phrase)
}

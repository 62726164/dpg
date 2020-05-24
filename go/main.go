package main

import (
	"crypto/sha512"
	"fmt"
	"golang.org/x/crypto/pbkdf2"
)

// Get a big password
func get_big(que []byte) string {
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

// Get a small password
func get_small(que []byte) string {
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

// Get a 7 word passphrase
func get_passphrase(que []byte) string {
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

// make the passwords easier to read
func readable(password string) string {
	human := ""
	for i := 0; i < len(password); i++ {
		if i > 0 {
			if i%3 == 0 {
				human += " " + string(password[i])
			} else {
				human += string(password[i])
			}
		} else {
			human += string(password[i])
		}
	}
	return human
}

func main() {
	dk := pbkdf2.Key([]byte("The sentence."), []byte("word"), 32768, 64, sha512.New)

	// Uncomment if needed to debug
	//fmt.Printf("%v \n", dk)
	//fmt.Printf("%x \n", dk)

	big := get_big(dk)
	small := get_small(dk)
	phrase := get_passphrase(dk)

	fmt.Printf("\n%s\n", "-----BEGIN DPG MESSAGE-----")
	fmt.Printf("%s\n", big)
	fmt.Printf("%s\n", small)
	fmt.Printf("%s\n", phrase)
	fmt.Printf("%s\n", "---------------------------")
	fmt.Printf("%s\n", "---- Human Readable -------")
	fmt.Printf("%s\n", "---------------------------")
	fmt.Printf("%s\n", readable(big))
	fmt.Printf("%s\n", readable(small))
	fmt.Printf("%s\n", readable(phrase))
	fmt.Printf("%s\n\n", "------END DPG MESSAGE------")
}

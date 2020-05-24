package main

import (
	"crypto/sha512"
	"fmt"
	"golang.org/x/crypto/pbkdf2"
)

func main() {
	dk := pbkdf2.Key([]byte("The sentence."), []byte("word"), 32768, 64, sha512.New)
	fmt.Printf("%v \n", dk)
	fmt.Printf("%x \n", dk)
}

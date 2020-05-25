package main

import (
	"crypto/sha512"
	"golang.org/x/crypto/pbkdf2"
	"html/template"
	"net/http"
)

func getBig(que []byte) string {
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

func getSmall(que []byte) string {
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

func getPhrase(que []byte) string {
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

func handle(w http.ResponseWriter, r *http.Request) {
	tmpl := template.Must(template.ParseFiles("index.html"))
	if r.Method != http.MethodPost {
		tmpl.Execute(w, nil)
		return
	}
	r.ParseForm()

	theSentence := r.PostFormValue("sentence")
	theWord := r.PostFormValue("word")

	dk := pbkdf2.Key([]byte(theSentence), []byte(theWord), 32768, 64, sha512.New)

	big := getBig(dk)
	small := getSmall(dk)
	phrase := getPhrase(dk)

	data := struct {
		S      string
		W      string
		Big    string
		Small  string
		Phrase string
	}{S: theSentence, W: theWord, Big: big, Small: small, Phrase: phrase}

	tmpl.Execute(w, data)
}

func main() {
	http.HandleFunc("/", handle)
	http.ListenAndServe("127.0.0.1:7977", nil)
}

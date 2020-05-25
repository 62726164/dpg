package main

import (
	"html/template"
	"net/http"
)

func getBig(s, w string) string {
	return "big"
}

func getSmall(s, w string) string {
	return "small"
}

func getPhrase(s, w string) string {
	return "phrase"
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

	big := getBig(theSentence, theWord)
	small := getSmall(theSentence, theWord)
	phrase := getPhrase(theSentence, theWord)

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

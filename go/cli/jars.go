package main

// The jar of numbers, returns map
func numbers() map[int]string {
	mp := make(map[int]string)
	nums := []string{"2", "3", "4", "5", "6", "7", "8", "9"}
	for i := 0; i < 32; i++ {
		for _, n := range nums {
			mp[len(mp)] = n
		}
	}
	return mp
}

// The jar of specials, returns map
func special() map[int]string {
	mp := make(map[int]string)
	spec := []string{".", ",", "!", "*", "#", "&", "^", "~"}
	for i := 0; i < 32; i++ {
		for _, s := range spec {
			mp[len(mp)] = s
		}
	}
	return mp
}

// The jar of lowers, returns map
func lower() map[int]string {
	mp := make(map[int]string)
	low := []string{"a", "b", "c", "d", "e", "f", "g", "h", "j", "k", "m", "n", "p", "r", "s", "t"}
	for i := 0; i < 16; i++ {
		for _, l := range low {
			mp[len(mp)] = l
		}
	}
	return mp
}

// The jar of uppers, returns map
func upper() map[int]string {
	mp := make(map[int]string)
	up := []string{"A", "B", "C", "D", "E", "F", "G", "H", "J", "K", "M", "N", "P", "R", "S", "T"}
	for i := 0; i < 16; i++ {
		for _, u := range up {
			mp[len(mp)] = u
		}
	}
	return mp
}

// The jar of words, returns map
func words() map[int]string {
	mp := make(map[int]string)
	for _, word := range theWords {
		mp[len(mp)] = word
	}
	return mp
}

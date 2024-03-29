package main

import "strings"

func Map(text string) map[string]int {
	wordCount := make(map[string]int)
	words := strings.Fields(text)
	for _, word := range words {
		wordCount[word]++

	}
	return wordCount
}

func Reduce(maps []map[string]int) map[string]int {
	result := make(map[string]int)
	for _, m := range maps {
		for word, count := range m {
			result[word] += count
		}
	}
	return result
}

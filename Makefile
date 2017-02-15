default:
	gcc main.c vigenere.c common.c -o crypto_yo
clean:
	rm crypto_yo

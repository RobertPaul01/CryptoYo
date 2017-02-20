default:
	gcc main.c affine.c vigenere.c common.c -o crypto_yo
clean:
	rm crypto_yo

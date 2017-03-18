default:
	cc -o crypto_yo main.c affine.c vigenere.c playfair.c common.c
clean:
	rm crypto_yo

default:
	cc -o run_tests run_tests.c affine.c vigenere.c playfair.c common.c
clean:
	rm run_tests

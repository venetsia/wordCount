coursework:
    cl wordcountMain.c
clean:
	del *.obj
	del *.exe
	del *.asm
fullSentences:
	wordcountMain -i sentences_test.txt -o output.txt -c
fullSingleWords:
	wordcountMain -i single_words_test.txt -o output.txt -c
inputOutputSentences:
	wordcountMain -i sentences_test.txt -o output.txt
inputOutputSingleWord:
	wordcountMain -i single_words_test.txt -o output.txt
inputCSentences:
	wordcountMain -i sentences_test.txt -c
inputCSingleWords:
	wordcountMain -i single_words_test.txt -c
inputSentences:
	wordcountMain -i sentences_test.txt
inputSingleWords:
	wordcountMain -i single_words_test.txt
outputC:
	wordcountMain -o output.txt -c
output:
	wordcountMain -o output.txt
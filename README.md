# SpellCheck
A spell checker implemented in the C programming language. 
The code has been adapted from one that was provided during a university course, and I implemented the spell checking function using a hashtable.

## Usage
Compile the code using the makefile. 
```
$ make speller
```

The code takes two arguments, a dictionary and the text file to spell check. Dictionaries are lists of words, included in ```./dictionaries```, and the sample text files are included in ```./texts```. 
```
$ ./speller ./dictionaries/\<dictionary file\> ./texts/\<text file to spell check\>
```

A sample usage:
```
$ ./speller ./dictionaries/large ./texts/lalaland.txt
```

Output:
```
<list of misspelled words>

WORDS MISSPELLED:     955
WORDS IN DICTIONARY:  143091
WORDS IN TEXT:        17756
TIME IN load:         0.04
TIME IN check:        0.02
TIME IN size:         0.00
TIME IN unload:       0.01
TIME IN TOTAL:        0.07
```

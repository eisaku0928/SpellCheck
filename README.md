# SpellCheck
A spell checker implemented in the C programming language. 
The code has been adapted from one that was provided during a university course, and I implemented the spell checking function using a hashtable.

## Usage
Compile the code using the makefile. 
```
$ make speller
```

The code takes two arguments, a dictionary and the text file to spell check. Dictionaries are lists of words, included in ```./dictionaries```, and the sample text files are included in ```./texts```. A sample usage is:
```
$ ./speller ./dictionaries/large ./texts/\<text file to spell check\>
```

# Sample C program
Small sample program executing different modules running from the console.
These modules are simple examples of C code, providing a fun, limited function.

## Modules
* Coin flip 
	* Flips a coin when the user hits enter, resulting in heads or tails, with a 50/50 chance.
	Records number of flips, and the result of each flip, to provide statistics.
* Number guesser
	* Asks the user to think of a number. This number is within a range, provided by the user.
	The module will try to guess the number, and if incorrect, ask if the guess is too high or too low.
	This information will modify the range, until the module guesses the correct number.
* Word counter
    * Counts number of words in a .txt file from subfolder txtfiles
* Character counter
    * Counts number of characters in a .txt file from subfolder txtfiles

## Execution
This repository includes a makefile, which will compile the samle program.
```
$ make
$ ./sample
```

If you wish to test only a specific module, make test, and execute testing with the corresponding argument.
```
$ make test
$ ./testing flip
```
* Coin flip - flip
* Number guesser - guess
* Word counter - wordc
* Character counter - charc



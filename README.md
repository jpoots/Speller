# CS50x Project 5
## Speller
### About
This project is an implementation of a spell checker using a hash table in C. Compatible dictionaries can be found in the "dictionaries" folder. Example texts to evalute can be found in the "texts" folder. I produced this in the mid stages of the CS50x course. Starter code and additional files for this project were obtained from https://cdn.cs50.net/2021/fall/psets/5/speller.zip.

Descriptions of the functions completed as part of the project have been obtained from the project website. Further details of the project can be found at https://cs50.harvard.edu/x/2022/psets/5/speller/.

### Usage

./speller dictionaries/[dictionary] texts/[text]

Where [dictionary] and [text] are replaced by the dictionary to be used and the text to be evaluated. The program will return misspelt words along with a number of statistics.

### Functions

#### load
This function loads the dictionary to be used into memory and returns true if successful. Otherwise, it returns false.

#### hash
This function hashes each word input to a number.

#### size
This function returns the number of words in the dictionary.

#### check
This function searches the dictionary for each word input, returning true if found. Otherwise, it returns false.

#### unload 
This function unloads the dictionary from memory and returns true if successful. Otherwise, it returns false.

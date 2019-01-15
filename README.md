# iHateReports
A solution to the 1001 reports you have to google and regurgitate.

## What is it about?
A small paraphraser project used to paraphrase paragraphs of text. A tongue twister I know.

## How to use?
1. Clone the project open up the folder iHateReports, in that folder you will 
see another folder iHateReports, folderception.

2. Place the text you want to paraphrase in paraphraseinput.txt. Run the code and you will find your paraphrased text in paraphrase.txt.

## Limitations
The accuracy of application currently depends largely on the accuracy and amount of data available. 
Without calling an established dictionary API, data is limited.

Reading of words with different tenses is not yet implemented, hence words with tenses that differ from the base words in the dictionary
will not get paraphrased.

## References
Dictionary data taken from http://www.gutenberg.org/ebooks/51155. References can be found in 51155-0.txt.

## Future implementations?
1. Implement reading of words with different tenses to reduce the amount of data needed (instead of treating the same word with
a different tense as a different word).

2. More punctuation consideration.

3. Allow for phrases to be synonyms.

4. Allow for phrases to be keys, a different method of reading text to accomodate this.

5. A priority system for synonyms, most used > least used.

## Disclaimers
This is just a little fun project to practice my c++ game. Feel free to clone/fork/reproduce at your leisure, preferably fork
and contribute here!;D

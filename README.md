# Cplusplus-Program
**Project Summary**: The goal was to input a running list of produce items purchased at a grocery store during the course of a day, from a file, and to make that information organized and accessible to a grocery store manager to help with evaluating store layout. Thanks to this program, the manager can look up a particular key (fruit/veg) to see how often it was purchased, or can quickly reference a list of all produce with corresponding purchase frequencies. Perhaps the manager will use this to experiment with relocating produce items that are purchased more or less frequently to particular locations in the store.

To accomplish this program, I opened the daily running list of purchases file, and input one item’s name at a time into a produce map, where each key represented a type of fruit or vegetable. Each key’s corresponding value represented the frequency of that word in the running file. For example, if Oranges appeared four times in the file, a pair could be: key = Oranges, value = 4 and pair (Oranges -> 4). 

**Successes (what I did well)** The organization and implementation were done well.  The order of implementation was as follows:
  First,  I created an empty map to hold each produce item type and sum. I used an input file stream to input each produce item, until it reached ‘end of file’. During this while-loop, if the item was not yet in the map, I added it. If it was already in the map, I incremented the value associated with that key. Next I used an output file stream to output the populated map to the back-up file. I created a class called Produce, and then used a for-loop to create all 20 Produce instances, and entered them into a vector.
	For the user interface, I included a welcome message and prompt. I set a bool called ‘runs’ to ‘true’ to enter while-loop, and at case 4, reassigned ‘runs’ to false to exit while-loop. For input validation, I threw a runtime error exception if cin.fail was true, or if userInput was not: 1, 2, 3, or 4. I chose to use a switch statement for each of the four cases because I like switch organization and simplicity. Although I practiced map for-loops and iteration for cases 1 and 2,  I made a point to use required class objects and Produce vector for case 3. 
 
**Ways to Further Enhance the code** The Switch statement’s ‘default’ may have caught the error and made the try, throw, catch blocks unnecessary. However I included the try/throw/catch blocks because I was afraid ‘default’ would not catch input failures. To enhance my code, I’d like to learn the best way to check for more types of error. If the user entered a full word, for instance, “Katie”, instead of a single character when prompted for a 1, 2, 3, or 4, the error message and menu re-printing was displayed for that many characters (in this case, five times). Fixing this would enhance the code.  
Biggest Challenges: I struggled to get the try/throw/catch to work with my while loop, partly because I wanted to update my while loop by inputting again at the end of the while loop, but then was confused because I may need to use another try/throw/catch. The order and organization of a while loop and this input validation was a challenge. 
The other challenges was just mastering a new topic, which was C++ mapping (dictionary). I had not known how to populate or access a C++ dictionary, and so had to read and try different strategies based my examples I found online, such as from learncpp.com, freecodecamp.org, w3schools, and Geeks for Geeks. I learned: 
 	**The following are new skills I learned during this project**
-How to populate a map from data in a file
   -first determine whether or not the key already exists in the map: 
      -if (map.count(key) == 0) key DNE in map.  Then add this key and set its value to 1
          to add the key, use the format: map.emplace(key,value)
      -if (map.count(key) == 1) key is ALREADY in map. 
          Then just increment it in the map, accessing the value using map.at(key) to access that key’s value:   map.at(produceItem) = map.at(produceItem) + 1;
-How to traverse through each map’s key-value pair in a for-loop in order to output each pair to a new file
     -for (auto const& pair : map) {           //for-loop format: for(a ref to each pair [:in] map)
		      outFS << pair.first << ": " << pair.second << endl;   } stream the first part of pair, then “: ”, then the second part of the pair.
**Most transferable new skills**
I look forward to using maps (dictionaries) in the future! They are a great option that I did not have mastered before this. I can even avoid creating some classes and objects by using dictionaries/maps exclusively. Also, from this project I have more practice with inputting data from a file, and outputting data to files.  

**How is this program maintainable, readable, and adaptable**
The program is readable and maintainable thanks to the ‘documentation’, aka in-line comments. I included a line above each function detailing its outcome. For almost every line of code, I stated what I accomplished (and when needed, reminders as to how). It is adaptable because I used variable names instead of numbers. I almost used the size of the resultant vector (20) in the code, but then changed it to a variable called vectorSize. Now the code can transfer to work with other inputted files, without unexpected results when there are more or less than 20 elements in the vector.


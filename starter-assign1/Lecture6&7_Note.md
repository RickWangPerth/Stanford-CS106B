# Stanford CS106B Winter 2022 Lecture 6 & 7
## Unorderd Data Strucutures: Sets and Maps
## Using Abstractions (Implementing Breadth-First Search)

Tower of Hanoi</br>
void towerOfHanoiThreeDisks(Stack<int>$ destination){</br>
  Stack<int> source = {3,2,1};</br>
  Stack<int> auxiliary;</br>
  destination.push(source.pop());</br>
  auxiliary.push(source.pop());</br>
  auxiliary.push(destination.pop());</br>
  destination.push(source.pop());</br>
  destination.push(auxiliary.pop());</br>
  destination.push(auxiliary.pop());</br>
}</br>


### Set
Set is a collection of elements with no duplicates</br>
add() contains() remove() size() isEmpty()</br>
Set<string> friedns;</br>
friends.add("Nick");</br>
  
for(string name : friends){}</br>

Set can be compared s1==s2 s1 != s2</br>
**Union** s1 + s2</br>
**Intersection** s1 * s2</br>
**Difference** s1 - s2</br>

### const 
const Vector<string>& lines => pass as reference to save menory and never edit it.
  
## Map
A map is a collection of key/value pairs, and the key is used ti quickly find the value.</br>
Map<string,string> phoneBook;</br>
phoneBook["Jenny"] = "873-1223"; OR .put("Jenny","821-1232");</br>
string jennyNumber = phoneBook["Jenny"] OR =phoneBook.get("Jenny");</br>
Map<string,Vector<double>> accounts;</br>

for(type curKey: map.keys()){}</br>

Find key:</br>
if(freqMap[key]==0){} will atuo insert the key with default value which will be always true.</br>
USE</br>
if(freqMap.containskey(key))</br>

### Countung Sort
string sortedString;</br>
for (char ch = 'a'; ch='z';ch++){</br>
  if(freqMap.containskey(key)){</br>
    for(int i = 0; i < freqMap[ch];i++){</br>
      sortedString += charToString(ch);</br>
    }</br>
  }</br>
}</br>

## Word ledders
Formalizing BFS Breath-First Search Data Structures
A data structure to represent(partial word) ladders => Stack<string> </br>
A data structure to store all the partial word ladders that we have generated so far and have yet to explore => Queue<Stack<string>> </br>
A data structure to kee track of all the words that we have explored so far so the we aviod getting stuck in loops => Set<string> </br>

Srack<string> findWordLadder(string startingWord, string destinationWord, Set<string>& dictionary){</br>
  Queue<Stack<string>> allLadders;</br>
  Set<string> visitedWords;</br>
  Stack<string> initailLadder = {startingWord};</br>
  allLadders.enqueue(initialLadder);</br>
  while(!allLadders.isEmpty()){</br>
    Stack<string>currentLadder =  allLadders.dequeue();</br>
    string currentWord = currentLadder.peek();</br>
    if (currentWord == destinationWord) return currentLadder'</br>
  }</br>
  Set<string> neighbors = generateBeighboringWords(currentWord, dictionary); </br>
  for(string neighbor:neighbors){</br>
    if(!visitedWOrds.contains(neighbor)){</br>
      Srack<string> newLadder = currentLadder;</br>
      newLadder.push(neighbor);</br>
      visitedWords.add(neighbor);</br>
      addLadders.enqueue(newLadder)</br>
    }</br>
  }</br>
}</br>


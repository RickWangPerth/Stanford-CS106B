# Lecture 4&5 2020 Summer
## Console Programs and Ordered Data Structures

### Get keyboard input & RETURN to exit
string inputStr = getLine("xxx"); </br>
if (inputStr == "") break;

### Console progeams must be run directly from main() 

### Vector(1D)

orderd collection of elemetns of the same type that can grow and shrink in size.</br>
Vector<int> vec;</br>
vec.add(4); </br>
OR </br>
Vector<int> vec = {4,8,5};</br>
cout << vec[1] << endl; </br>

**for loop / for each:**
for (int i=0; i < vec.size(); i++){} </br>
for (int num : vec){}

### Reference
**pass by values:** When parameter is padded into a function, the new variable stroes a copy of the passed in value in memory.</br>
**pass by reference:** When parameter is padded into a function,the new variable stroes a reference to the passed in value, which allows you to directly edit the original value. </br>
void tripleWeight(double& weight_ref){}</br>
To avoid making new copies of larfe data structures in memory</br>
For multiple return values</br>

### Grid (stanford library)
A 2D array, defined with a particular width and height.
Grid<int> board;</br>
board.resize(2,3);</br>
board[0][0] = 2;</br>
OR</br>
Gird<int> board(3,3);</br>
OR</br>
Grid<int> board = {{2,0},{{6,0}};</br>
grid.numRows() grid.numCols() grid.inBounds()</br> 

### Struct (stanford library)
A way to bundle different types of information in C++ - like creating a custom data structure.</br>
struct GridLocation{</br>
  int row;</br>
  int col;</br>
};</br>

GridLocation origin = {0,0};</br>

### Queues
First In First Out
enqueue() dequeue() peek() isEmpty()</br>
Queue<int> queue1;</br>
dont use .size(0 in the loop's conditions!
  
### Stack
Last In First Out
push() pop() peek()</br>
Stack<int> queue1;
cannot iterate a stack without destroying it</br>
dont use .size(0 in the loop's conditions!

The undo button in a text editor - Stacks
Jobs submitted to a printer that can also be cancelled - Vectors
LaIR requests - Queues
Your browsing history - Vectors
Google spreadsheets - Grids
Call centers - Queues





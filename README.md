# Data Structure Practice

This project was inspired by [@jwasham's](https://github.com/jwasham) project [practice-c](https://github.com/jwasham/practice-c). I used some of his function headers and initial implementations for the Array library to kickstart my project, but I'm implementing on my own as I go.

This is a playground for practicing data structures. I plan to implement each data structure from scratch as a library. I'll possibly add functions that do "cool tricks." I'll revisit my implementations over time to try to improve performance. Here's the list of what I plan to implement, and you can see progress so far.

- [ ] Array (in progress)
- [ ] Stack
- [ ] Queue
- [ ] Linked List
- [ ] Tree
- [ ] Heap
- [ ] Trie
- [ ] Graph
- [ ] Hash Table
- [ ] Map

## What does the code do?
By itself? Not a lot! This is a collection of stand-alone libraries. You could write your own code and link the libraries in to play around with the interfaces. Alternatively, you can run the Unity tests to make sure everything works :) Eventually, I might add a simple CLI to interact with and visualize the data structures... but no promises.

## Building and running the code
The project uses [CMake](https://cmake.org) and the [Unity test framework](http://www.throwtheswitch.org/unity). To build and run it yourself:

1. Clone this repository:
```bash
git clone https://github.com/masonmem/data-structure-practice-c.git
```

2. Create a build directory and create the Makefile with CMake:
```bash
cd data-structure-practice-c
mkdir build
cd build
cmake ..
```

3. Build the project using the new MakeFile in the `build` directory. 
```bash
make
```

4. Run the new executable from within the build directory. This will change... for now, it's all I have!
```bash
./tst/array/RunArrayTest
```

# dynamic array realization in C (std=c99)
## guys dont mind me my english sucks so much :\_)

i tried to create my own dynamic array version in pure C (with the C99 standart), and this is what i created

i would be happy to review any pull requests, so feel free to test this header file and suggest improvements to make this project even better

let's begin

# including
after using `git clone this-repo`, you will have a directory containing this project<br>
next, in your `.c` file, you need to include the header file by typing `#include "path/to/da.h"`<br>
this will include the contents of the `.h` file, allowing you to use the projects functions

# what is a project structure?
so, the `da.h` file contains the Header structure and macro functions<br>

## how everything does work?
i'll describe how everything works:

the structure, Header, is a data structure that holds it's count (the length in size_t), and the capacity (also in size_t)

you can create an array of any type, and for the better experience, you can declare it as NULL<br>
then you can use da_push macro to push some data into array<br>
it'll allocate space for 2 elements, and then process to allocate memory when you need it (your elements are safe, no worries)<br>
yeah, types dont matter here

to get length, you can use da_length

to pop, well, just use da_pop

## so, now I'm gonna talk about macros in my project
every macro has a prefix da, so there is no name conflicts

# bye
have fun guys, and don't forget to report every issue<br>
see you soon :D

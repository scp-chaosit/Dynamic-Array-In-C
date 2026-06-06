# dynamic array realization in C (std=c99)
## (guys dont mind me my english sucks so much)

tried to create mine dynamic array version in pure C (with standart of C99), and this is what I created

I'll be happy to read every single pull request, so feel free to test this header file and send me some things that I can do, so my "project" will be even better

okay, let's begin

# including
after using `git clone this-repo`, you will have a directory with this project, but what is next?<br>
in your `.c` file, you need to type `include "path/to/da.h"` - this will include the `.h` file contents so you will be able to use the projects functions

# what is a project structure?
README.md and LICENSE files are here for github, I'm not gonna describe why they are here XD

so, the `da.h` is a file that contains Header structure and macro functions<br>

## how everything does work?
I'll describe how everything do works:

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

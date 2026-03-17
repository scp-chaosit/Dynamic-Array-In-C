# dynamic array realization in C (std=c99)
tried to create mine dynamic array version in pure C (with standart of C99), and this is what I created

I'll be happy to read every single pull request, so feel free to test this header file and send me some things that I can do, so my "project" will be even better

okay, let's begin

# including
after using `git clone this-repo`, you will have a directory with this project, but what is next?<br>
in your `.c` file, you need to type `include "path/to/func_da.c"` - this will include the `.c` and `.h` files contents so you will be able to use the projects functions

# what is a project structure?
README.md and LICENSE files are here for github, I'm not gonna describe why they are here XD

so, the `func_da.c` is a file that contains functions definition<br>
the `da.h` file (that I was using for the whole time before this update) has the structure and functions declarations - wanna build something on your own - include `da.h`, or just copy the `da.h` structure code and do whatever you want :D

## how everything does work?
WARNING: YOUR ARRAY SHOULD BE A POINTER

I'll describe how everything do works:

my structure, Array (array\_t by typedef), is a data structure that holds it's length (in long type), and the array itself (void\*\*)<br>

everytime you are defining a new array\_t, you should use the da\_constructor function - it will set up the length of your array, will allocate memory for an array (with the size of your array)<br>
if your array's length is negative, ALL the functions that take the length will just take it positive value (or, to keep words simple, they'll make the length positive if they are negative)<br>

in the next section I'll talk about the properties of the Array structure<br>
the length has a long data type, and as I mentioned before - it will turn the negative number positive, and will always be used in the user arrays<br>
the void\*\* is used so you can store data of every data type (like dynamic typing), there are some examples about:<br>
iterating in the array:<br>
```
array_t *arr = da_constructor (10);

printf ("arr: ");
for (int i = 0; i < arr->length; ++i) {
    arr->array[i] = (void *)(long)i+1;

    printf ("%ld ", (long)arr->array[i]);
}
printf ("\n");
```

## so, now I'm gonna talk about functions in my project

the setLength function is a function that takes two arguments:<br>
array\_t pointer (which we will later reallocate), new array length to set

the next thing is allocateArr function - it is used to, well, allocate an array by the size of void\* multiplied by the number of elements<br>
takes the array\_t pointer to allocate an array

also, we have a freeArray function - will take the array\_t pointer, free's it, and set's the pointer to NULL<br>
it is here because, well? it may get pretty boring writing: `free (arr); arr = NULL;`, so, why not?

## bye
have fun guys, and don't forget to report every issue!<br>
see you soon :D

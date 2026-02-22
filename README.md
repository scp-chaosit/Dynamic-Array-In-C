# dynamic array realization in C (std=c99)
tried to create mine dynamic array version in pure C (with standart of C99), and this is what I created

I'll be happy to read every single pull request, so feel free to test this header file and send me some things that I can do, so my "project" will be even better

okay, no time...

## how everything does work?
I'll describe how everything do works:

my structure, Array (array\_t by typedef), is a data structure that holds it's length (in long type), and the array itself (void\*\*)<br>
you should use array\_t in your code, not Array - Array was used so I can have some function pointers and they will work as "methods" in OOP

everytime you are defining a new array\_t, you should use the da\_constructor function - it will set up the length of your array, will allocate memory for an array (with the size of your array)<br>
and will also setup every function pointer so they'll actually work as "methods" in OOP<br>
if your array's length is negative, ALL the functions that take the length will just take it positive value (or, to keep words simple, they'll make the length positive if they are negative)<br>

in the next section I'll talk about the properties of the Array structure<br>
the length has a long data type, and as I mentioned before - it will turn the negative number positive, and will always be used in the user arrays<br>
the void\*\* is used so you can store data of every data type (like dynamic typing), there are some examples about:<br>
iterating in the array:<br>
```
array_t *arr = da_constructor (10);

printf ("arr: ");
for (long i = 0; i < arr->length; ++i) {
    arr->array[i] = (void *)i+1;

    printf ("%ld ", (long)arr->array[i]);
}
printf ("\n");
```

## so, now I'm gonna talk about the setLength function pointer in the Array structure (from now on I'm referencing them as methods)<br>

the setLength method is a function pointer that takes three arguments:<br>
array (which we will later reallocate), length of the current array (to change it), length to set (basically the new array length)<br>
so, um, the array is the Array structure method, that is used to, well, store your data<br>
the length of an array... should I really describe it?<br>
okay, this thing is pretty important too - if you'll set your new length to be negative, it will automatically be set to the positive, so be careful with messing around

the next thing is allocateArr method - it is used to, well, allocate an array by the size of void\* multiplied by the number of elements<br>
takes the array (of void** data type, or simply the array type of Array structure), and the length of an array (better use the Array structure property, or may have the heap overflow)

also, we have a freeArray method - will take the array\_t pointer, free's it, and set's the pointer to NULL<br>
it is here because, well? it may get pretty boring writing: `free (arr); arr = NULL;`, so, why not?

## bye
have fun guys, and don't forget to report every issue!<br>
see you soon :D

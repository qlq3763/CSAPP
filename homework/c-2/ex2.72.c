/* You are given the task of writing a function that will copy an integer val into a */
/* buffer buf, but it should do so only if enough space is available in the buffer. */
/* Here is the code you write: */
/* /\* Copy integer into buffer if space is available *\/ */
/* /\* WARNING: The following code is buggy *\/ */
/* void copy_int(int val, void *buf, int maxbytes) { */
/* if (maxbytes-sizeof(val) >= 0) */
/* memcpy(buf, (void *) &val, sizeof(val)); */
/* } */
/* This code makes use of the library function memcpy. Although its use is a bit */
/* artificial here, where we simply want to copy an int, it illustrates an approach */
/* commonly used to copy larger data structures. */
/* You carefully test the code and discover that it always copies the value to the */
/* buffer, even when maxbytes is too small. */
/* A. Explain why the conditional test in the code always succeeds. Hint: The */
/* sizeof operator returns a value of type size_t. */
/* B. Show how you can rewrite the conditional test to make it work properly. */

/* A. */
/* For sizeof returns a value of type size_t(unsigned), so the type in the  */
/* comparation expression will be coverted to size_t. And as we all know,  */
/* size_t type always has value grater than or equal to zero */

/* B. */
// version one:
// change type of maxbytes to size_t, and change comparation expression to:
// max_bytes >= sizeof(val)

// version two:
// explicitly covert sizeof(val) to int: (int)sizeof(val)

// version three:
// like version one, but convert  type sizeof(val) to int

// Conclusion:
// 1. DO NOT use mixed types.
// 2. DO NOT use -(minus) in comparation(especially unsigned comparation) 
//    expression.
// 3. Repete: Compare directly, DO NOT waste additional effort.

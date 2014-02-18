
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

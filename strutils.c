/*
 *  strutils.c
 *  maulib
 *
 *  Created by Jason Hullinger on 6/12/10.
 *
 */

#include "strutils.h"

/*
 *-------------------------------------------------------------------------------
 *
 * strmalloc --
 *
 *		Malloc's a char ptr buffer initialized with all bit's being null
 *
 * Returns:
 *      A malloc'ed null buffer
 *
 * Side effects:
 *				None.
 *
 *-------------------------------------------------------------------------------
 */
char* 
str_malloc(size_t len){ /* IN */
	char *buff = (char*)malloc(len);
	memset(buff, '\0', len);
	return buff;
}

/*
 *-------------------------------------------------------------------------------
 *
 * prepend_cstring --
 *
 *     Creates a malloc'ed string with the contents of a const cstring. The
 *		caller is reponsible for freeing the returned value.
 *
 * Returns:
 *      A malloc'ed cstring.
 *
 * Side effects:
 *				None.
 *
 *-------------------------------------------------------------------------------
 */
char* 
create_new_cstring(const char* strin) /* IN */
{
	size_t bufflen = (sizeof(char)*strlen(strin))+1;
	char *str = str_malloc(bufflen);
	strncpy(str, strin, strlen(strin));
	return str;
}

/*
 *-------------------------------------------------------------------------------
 *
 * append_cstring --
 *
 *     Creates a malloc'ed cstring by appending contents of another cstring. 
 *		The caller is responsible for freeing the return value and the input 
 *		cstring.
 *
 * Returns:
 *      A malloc'ed cstring.
 *
 * Side effects:
 *				None.
 *
 *-------------------------------------------------------------------------------
 */
char*
append_cstring(char *strin, /* IN */
			   const char *strappend) /* IN */
{
	size_t bufflen = (sizeof(char*)*(strlen(strin)+strlen(strappend)))+1;
	char *str = str_malloc(bufflen);
	memmove(str, strin, strlen(strin));
	memmove(str+strlen(strin), strappend, strlen(strappend));
	return str;
}

/*
 *-------------------------------------------------------------------------------
 *
 * secure_free_cstring --
 *
 *		Sets the contents of a malloc'ed buffer to null, then free's it
 *
 * Returns:
 *      None
 *
 * Side effects:
 *				None.
 *
 *-------------------------------------------------------------------------------
 */
void
secure_free_cstring(char *buffer) /* IN */
{
	size_t buffer_len = (sizeof(char)*strlen(buffer));
	memset(buffer, '\0', buffer_len);
	free(buffer);
}

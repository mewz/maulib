/*
 * strutils.h
 * maulib
 *
 * Created by Jason Hullinger on 6/12/10.
 *
 */

#ifndef __MAULIB_STR_UTILS_H__
#define __MAULIB_STR_UTILS_H__

#include <stdlib.h>
#include <string.h>

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
char*	str_malloc(size_t len); /* IN */


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
char*	create_new_cstring(const char* strin); /* IN */

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
char*	append_cstring(char *strin, /* IN */
					   const char *strappend); /* IN */

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
void	secure_free_cstring(char *buffer); /* IN */

#endif
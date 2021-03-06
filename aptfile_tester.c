/*
 Testing mechanism for aptfile.c; not to be shipped in the final version.

gcc aptfile_tester.c aptfile.c $(pkg-config glib-2.0 --cflags --libs) -o aptfile_tester

*/

#include "config.h"
#include "aptfile.h"

#include <stdio.h>

int
main(int argc, char **argv)
{
	gchar *result = NULL;
	gboolean ok;

	if (argc<2) {
		printf ("Give the package name.\n");
		return 1;
	}

#if 0
	printf ("Looking up: %s\n", argv[1]);
	
	result = aptfile_owner_package (argv[1]);

	printf ("Result is: %s\n", result);
#endif

	ok = aptfile_attempt_installation (argv[1]);
	printf ("Attempted installation of %s: result was %d.\n",
		argv[1], ok);

	return 0;
}


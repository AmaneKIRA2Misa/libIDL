#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#ifdef IDL_LIBRARY
#include "IDL.h"
#else
#include <libIDL/IDL.h>
#endif

#if 0
void IDL_ns_rcs_traverse(IDL_tree p)
{
	if (p == NULL)
		return;

	assert(IDL_NODE_TYPE(p) == IDLN_GENTREE);

	while (p != NULL) {
		if (IDL_GENTREE(p).children == NULL) {
			IDL_tree q;
			char *s;
			int levels;

			q = IDL_GENTREE(p).data;

			q = IDL_get_parent_node(q, IDLN_INTERFACE, &levels);
			
			if (q != NULL) {

				printf("node type: %s levels %d\n", IDL_NODE_TYPE_NAME(q), levels);
				
				s = IDL_ns_ident_to_qstring(p, "_", levels);

				
			} else {
				s = IDL_ns_ident_to_qstring(p, "_", 0);
			}


			if (s != NULL)
				printf("%s\n", s);

			free(s);

		} else
			IDL_ns_rcs_traverse(IDL_GENTREE(p).children);
		p = IDL_GENTREE(p).siblings;
	}
}

#else
void IDL_ns_rcs_traverse(IDL_tree p)
{
	printf("traversing namespace\n");
}
#endif

void IDL_ns_dump_namespace(IDL_ns ns)
{
	IDL_ns_rcs_traverse(IDL_NS(ns).global);
}

int main(int argc, char *argv[])
{
	int rv;
	IDL_tree tree;
	IDL_ns ns;
	char *fn;
	extern int __IDL_debug;

	IDL_check_cast_enable(IDL_TRUE);
	__IDL_debug = 0;

	if (argc < 2) {
		fprintf(stderr, "usage: tstidl <filename> [fold constants, 0 or 1]\n");
		exit(1);
	}

	fn = argv[1];

	rv = IDL_parse_filename(fn, NULL, NULL, &tree, &ns, argc == 3 ? atoi(argv[2]) : 0);

	if (rv == IDL_SUCCESS) {
		void __IDL_tree_print(IDL_tree p);

		__IDL_tree_print(tree);
#if 1
		IDL_ns_dump_namespace(ns);
#endif
		printf("Freeing Namespace\n");
		IDL_ns_free(ns);
		printf("Freeing Tree\n");
		IDL_tree_free(tree);
		
	}
	else if (rv == IDL_ERROR) {
		fprintf(stderr, "tstidl: IDL_ERROR\n");
		exit(1);	
	}
	else if (rv < 0) {
		perror(fn);
		exit(1);
	}
	
	return 0;
}

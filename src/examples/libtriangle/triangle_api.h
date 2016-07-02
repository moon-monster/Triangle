#ifndef TRIANGLE_API_H
#define TRIANGLE_API_H

#include <triangle.h>

#include <stdio.h>
#include <stdlib.h>

#define EXPORT __declspec(dllexport)

#ifdef __cplusplus
extern "C" {
#endif

	typedef struct context_t {
		mesh *m;
		behavior *b;
	} context;

	EXPORT context* triangle_context_create();

	EXPORT VOID triangle_context_destory(context* ctx);

	EXPORT int triangle_options(context* ctx, char *options);

	EXPORT int triangle_mesh(context* ctx, triangleio *in);

	EXPORT int triangle_refine(context* ctx);

	EXPORT int triangle_output(context* ctx, triangleio *out);

	EXPORT int triangle_quality_statistics(context *ctx, statistics *stats);

	EXPORT int triangle_write_nodes(context *ctx, FILE *nodefile);

	EXPORT int triangle_write_elements(context *ctx, FILE *elefile);

	EXPORT int triangle_write_poly(context *ctx, FILE *polyfile,
		REAL *holelist, int holes, REAL *regionlist, int regions);

	EXPORT int triangle_write_edges(context *ctx, FILE *edgefile);

	EXPORT int triangle_write_neighbors(context *ctx, FILE *neighborfile);

#ifdef __cplusplus
}
#endif

#endif /* TRIANGLE_API_H */
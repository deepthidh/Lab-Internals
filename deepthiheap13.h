#ifndef _INCLUDED_HEAP_
#define _INCLUDED_HEAP_

#include <stdint.h>
#define HEAP_MAX_SIZE 32

typedef struct _theap_ THeap;
typedef struct _theap_ PHeap;
typedef struct _theap_ EHeap;
struct  _heap_
{
	uint32_t	size;
	int32_t		data[HEAP_MAX_SIZE]	;
};
struct  _Pheap_
{
	uint32_t	size;
	int32_t		data[HEAP_MAX_SIZE]	;
};
struct  _Eheap_
{
	uint32_t	size;
	char	data[HEAP_MAX_SIZE]	;
};


THeap 		heap_tnew(int32_t data[], uint32_t len);
PHeap 		heap_pnew(int32_t data[], uint32_t len);
EHeap 	    heap_eventnew(char data[], uint32_t len); 
THeap*	    heap_sort(THeap *heap);
THeap*	    heap_time_insert(THeap *heap, int32_t key);
PHeap*	    heap_plane_insert(PHeap *heap, int32_t key);
EHeap*	    heap_event_insert(EHeap *heap, char key);
THeap*	    heap_time_test(THeap *heap);
PHeap*	    heap_plane_test(PHeap *heap);

/*int32_t		heap_get_max(Heap *heap);
int32_t		heap_extract_max(Heap *heap);*/
uint32_t	heap_time_size(THeap *heap);
uint32_t	heap_plane_size(THeap *heap);
uint32_t	heap_event_size(EHeap *heap);

#endif
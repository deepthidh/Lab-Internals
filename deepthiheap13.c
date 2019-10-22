#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "deepthiheap13.h"


static void _swap_(int32_t *data1, int32_t *data2) {
	int32_t temp = *data1;
	*data1 = *data2;
	*data2 = temp;
}

static void _heapify_ (int32_t data[], uint32_t len, uint32_t parent) {
	assert (len > 0 && len < HEAP_MAX_SIZE && parent > 0 );

	uint32_t child = 2 * parent;

	while (child <= len) {
		if (child + 1 <= len) {
			if (data[child+1] > data[child]){
				++child;
			}
		}
		if (data[parent] >= data[child]) {
			break;
		}
		_swap_(&data[parent], &data[child]);
		parent = child;
		child = 2 * parent;
	}
}

static void _test_time_heap_(int32_t data[], uint32_t len) {

	for (uint32_t child = len; child > 1; --child) {
		assert(data[child] <= data[child/2]);
	}

}
static void _test_plane_heap_(int32_t data[], uint32_t len) {

	for (uint32_t child = len; child > 1; --child) {
		assert(data[child] <= data[child/2]);
	}

}

static void _test_event_heap_(char data[], uint32_t len) {

	for (uint32_t child = len; child > 1; --child) {
		assert(data[child] <= data[child/2]);
	}

}

THeap*	heap_time_test(THeap *theap)
{
	_test_time_heap_(theap->data, theap->size);
}
PHeap*	heap_plane_test(PHeap *pheap)
{
	_test_plane_heap_(pheap->data, pheap->size);
}
EHeap*	heap_event_test(EHeap *eheap)
{
	_test_event_heap_(eheap->data, eheap->size);
}

THeap 	heap_tnew(int32_t data[], uint32_t len) {
	assert (len > 0 && len < HEAP_MAX_SIZE);

	Heap theap;
	uint32_t idx = len/2;
	for (idx = len/2; idx > 0; --idx) {
		_heapify_(data, len, idx);
	}
	theap.size = len;
	memcpy(theap.data, data, (len+1) * sizeof(int32_t));
	_test_time_heap_(theap.data, theap.size);

	return heap;
}
PHeap 	heap_pnew(int32_t data[], uint32_t len) {
	assert (len > 0 && len < HEAP_MAX_SIZE);

	PHeap pheap;
	uint32_t idx = len/2;
	for (idx = len/2; idx > 0; --idx) {
		_heapify_(data, len, idx);
	}
	pheap.size = len;
	memcpy(pheap.data, data, (len+1) * sizeof(int32_t));
	_test_plane_heap_(pheap.data, pheap.size);

	return pheap;
}
EHeap 	heap_eventnew(char data[], uint32_t len) {
	assert (len > 0 && len < HEAP_MAX_SIZE);

	EHeap eheap;
	uint32_t idx = len/2;
	for (idx = len/2; idx > 0; --idx) {
		_heapify_(data, len, idx);
	}
	heap.size = len;
	memcpy(eheap.data, data, (len+1) * sizeof(int32_t));
	_test_eventheap_(eheap.data, eheap.size);

	return eheap;
}

THeap*	heap_sort(THeap *theap) {
	assert (heap->size > 0 && heap->size < HEAP_MAX_SIZE);

	uint32_t idx = theap->size;

	for (idx = theap->size; idx > 1; idx--) {
		_swap_(&theap->data[idx], &theap->data[1]);
		_heapify_(theap->data, idx-1, 1);
	}

	return theap;
}


THeap*	heap_time_insert(THeap *heap, int32_t key)
{
	assert (heap->size > 0 && heap->size+1 < HEAP_MAX_SIZE);

	++heap->size;
	uint32_t parent = heap->size/2;
	uint32_t loc = heap->size;

	while ( loc > 1 && heap->data[parent] < key) {
		heap->data[loc] = heap->data[parent];
		loc = parent;
		parent = parent/2;
	}
	heap->data[loc] = key;
	return heap;

}
PHeap*	heap_plane_insert(PHeap *heap, int32_t key)
{
	assert (heap->size > 0 && heap->size+1 < HEAP_MAX_SIZE);

	++heap->size;
	uint32_t parent = heap->size/2;
	uint32_t loc = heap->size;

	while ( loc > 1 && heap->data[parent] < key) {
		heap->data[loc] = heap->data[parent];
		loc = parent;
		parent = parent/2;
	}
	heap->data[loc] = key;
	return heap;

}
EHeap*	heap_event_insert(Heap *heap, char key)
{
	assert (heap->size > 0 && heap->size+1 < HEAP_MAX_SIZE);

	++heap->size;
	uint32_t parent = heap->size/2;
	uint32_t loc = heap->size;

	while ( loc > 1 && heap->data[parent] < key) {
		heap->data[loc] = heap->data[parent];
		loc = parent;
		parent = parent/2;
	}
	heap->data[loc] = key;
	return heap;

}

/*int32_t		heap_get_max(Heap *heap)
{
	assert (heap->size > 0 && heap->size < HEAP_MAX_SIZE);
	return heap->data[1];

}

int32_t		heap_extract_max(Heap *heap)
{
	assert (heap->size > 0 && heap->size < HEAP_MAX_SIZE);

	int32_t max = heap->data[1];	
	_swap_(&heap->data[1], &heap->data[heap->size]);
	--heap->size;
	_heapify_(heap->data, heap->size, 1);

	return max;
}*/

uint32_t	heap_time_size(THeap *heap)
{
	assert (heap->size > 0 && heap->size < HEAP_MAX_SIZE);
	return heap->size;
}
uint32_t	heap_plane_size(PHeap *heap)
{
	assert (heap->size > 0 && heap->size < HEAP_MAX_SIZE);
	return heap->size;
}
uint32_t	heap_event_size(EHeap *heap)
{
	assert (heap->size > 0 && heap->size < HEAP_MAX_SIZE);
	return heap->size;
}
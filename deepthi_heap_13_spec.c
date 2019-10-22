#include <stdint.h>
#include <assert.h>
#include "heapp.h"

void test_sort( int32_t data[], uint32_t len) 
{
	uint32_t idx;
	for (idx = 1; idx <= len; ++idx) {
		assert (data[idx] <= data[idx+1]);		
	}
}

void test_heap()
{
	int32_t data[] = { 1015,1137,3015,4030,1230,1030,5045,2050};
	THeap 	heap_tnew(data[], 8;
	heap_time_insert(&heap, 6025);
	heap_time_test(&heap);
	/*assert(heap_get_max(&heap) == 93);
	assert(heap_extract_max(&heap) == 93);
	heap_test(&heap);
	assert(heap_size(&heap) == 10);*/

	heap_sort(THeap *heap) {
	test_sort(heap.data, 1130);

}

int main()
{
	test_heap();
	return 0;
}
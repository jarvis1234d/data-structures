#include <stdio.h>
#include <stdlib.h>

int main(){

	int *nums = malloc(3*sizeof(int));
	if(nums == NULL){
		return 1;
	}
	nums[0] = 0;
	nums[1] = 1;
	nums[2] = 2;

	int *tmp = malloc(4*sizeof(int));
	if(tmp == NULL){
		return 1;
	}
	for(int i = 0, size = 3; i < size; i++){
		tmp[i] = nums[i];
	}

	tmp[3] = 3;
	free(nums);
	nums = tmp;
	
	for (int i = 0, size = 4; i < size; i++){
		printf("nums[%i]: %i\n", i, nums[i]);
	}

	free(nums);
	return 0;
}
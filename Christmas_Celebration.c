#include <stdio.h>

int central(int, int, int);
int lines(int, int, int);

int main(int argc, char *argv[]) {
	int num_layers, top_side_length, growth, trunk_width, trunk_height;
	printf("Enter the number of layers (2 to 5) = ");
	scanf("%d", &num_layers);
	printf("Enter the side length of the top layer = ");
	scanf("%d", &top_side_length);
	printf("Enter the growth of each layer = ");
	scanf("%d", &growth);
	printf("Enter the trunk width (odd number, 3 to 9) = ");
	scanf("%d", &trunk_width);
	printf("Enter the trunk height (4 to 10) = ");
	scanf("%d", &trunk_height);

	// Allow Monkey Test
	while (num_layers < 2 || num_layers > 5) {
		printf("***The layers is invalid, please try again***\n");
		printf("Enter the number of layers (2 to 5) = ");
		scanf("%d", &num_layers);
	}
	while ((trunk_width < 3 || trunk_width > 9) || (trunk_width % 2 == 0)) {
		printf("***Th trunk width is invalid, please try again***\n");
		printf("Enter the trunk width (odd number, 3 to 9) = ");
		scanf("%d", &trunk_width);
	}
	while (trunk_height < 4 || trunk_height > 10) {
		printf("*** The trunk height is invalid, please try again***\n");
		printf("Enter the trunk height (4 to 10) = ");
		scanf("%d", &trunk_height);
	}
	
	// Print out Christmas Tree
	// Top layer
	for (int i = 0; i < top_side_length; i++) {
		// Medium lines
		if (i != top_side_length - 1 && i != 0) {
			for (int j = i + 1; j < central(top_side_length, growth, num_layers); j++) {
				printf(" ");
			}
			printf("#");
			for (int j = 0; j < (2 * i) - 1; j++) {
				printf("@");
			}
			printf("#\n");
		// First line
		} else if (i == 0) {
			for (int j = i + 1; j < central(top_side_length, growth, num_layers); j++) {
				printf(" ");
			}
			printf("#\n");
		// Last line
		} else {
			for (int j = i + 1; j < central(top_side_length, growth, num_layers); j++) {
				printf(" ");
			}
			for (int j = 0; j < (2 * i) + 1; j++) {
				printf("#");
			}
			printf("\n");
		}
	}
	// Remain layers
	for (int i = 1; i < num_layers; i++) {
		for (int j = 1; j <= lines(top_side_length, growth, i); j++) {
			for (int k = j + 1; k < central(top_side_length, growth, num_layers); k++) {
				printf(" ");
			}
			if (j != lines(top_side_length, growth, i)) {
				printf("#");
				for (int k = 0; k < j * 2 - 1; k++) {
					printf("@");
				}
				printf("#\n");
			// Last line
			} else {
				for (int k = 0; k < j * 2 + 1; k++) {
					printf("#");
				}
				printf("\n");
			}
		}
	}

	// Trunks
	for (int i = 1; i <= trunk_height; i++) {
		for (int j = 1 + trunk_width / 2; j < central(top_side_length, growth, num_layers); j++) {
			printf(" ");
		}
		for (int j = 0; j < trunk_width; j++) {
			printf("|");
		}
		printf("\n");
	}

	return 0;
}

int central(int side_length, int growth, int layers) {
	return side_length + growth * (layers - 1);
}

// The number of lines in each layers
int lines(int side_length, int growth, int layers) {
	return side_length + growth * layers - 1;
}

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    float num1, num2, result;

    while(1) {
        printf("Basic Calculator Program\n");
        printf("------------------------\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n");
        
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("Exiting program...\n");
            break;
        }

        if (choice >= 1 && choice <= 4) {
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);

            switch(choice) {
                case 1:
                    result = num1 + num2;
                    printf("Result = %.2f\n", result);
                    break;
                case 2:
                    result = num1 - num2;
                    printf("Result = %.2f\n", result);
                    break;
                case 3:
                    result = num1 * num2;
                    printf("Result = %.2f\n", result);
                    break;
                case 4:
                    if (num2 != 0)
                        printf("Result = %.2f\n", num1 / num2);
                    else
                        printf("Error: Division by zero\n");
                    break;
            }
        } else {
            printf("Invalid choice! Please select 1-5.\n");
        }

        printf("\n");
    }

    return 0;
}
#include <stdio.h>

#define MAX 100

void addValue(float arr[], int *n, float val);
int searchValue(float arr[], int n, float val);
void printArray(float arr[], int n);
void printRange(float arr[], int n, float minVal, float maxVal);
void sortAndPrintArray(float arr[], int n);

int main()
{
    float arr[MAX];
    int n = 0, choice;
    float val, minVal, maxVal;

    do
    {
        printf("\nMenu:\n");
        printf("1. Them gia tri\n");
        printf("2. Tim kiem gia tri\n");
        printf("3. In mang\n");
        printf("4. In gia tri trong pham vi\n");
        printf("5. In ra mang the thu tu tang dan\n");
        printf("6. Exit\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        
        switch (choice){
        	case 1:
        		printf("Nhap vao gia tri de them: ");
        		scanf("%f", &val);
        		addValue(arr, &n, val);
				break;
			case 2: 
				printf("Nhap vao gia tri de tim: ");
				scanf("%f", &val);
				printf("Gia tri %f xuat hien %d lan\n", val, searchValue(arr, n, val));
				break;
			case 3:
				printArray(arr, n);
				break;
			case 4:
				printf("Nhap vao gia tri nho nhat: ");
				scanf("%f", &minVal);
				printf("Nhap vao gia tri lon nhat: ");
				scanf("%f", &maxVal);
				printRange(arr, n, minVal, maxVal);
				break;
			case 5:
				sortAndPrintArray(arr, n);
				break;
			case 6:
				printf("Exiting program...\n");
				break;
			default:
				printf("Lua chon khong hop le !\n");
		}
	} while (choice != 6);
	return 0;
}

void addValue(float arr[], int *n, float val)
{
    if (*n < MAX)
    {
        arr[*n] = val;
        (*n)++;
    }
    else
    {
        printf("Array is full!\n");
    }
}

int searchValue(float arr[], int n, float val)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == val)
            count++;
    }
    return count;
}

void printArray(float arr[], int n)
{
    printf("Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%f ", arr[i]);
    }
    printf("\n");
}

void printRange(float arr[], int n, float minVal, float maxVal)
{
    printf("Values in range [%f, %f]: ", minVal, maxVal);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= minVal && arr[i] <= maxVal)
            printf("%f ", arr[i]);
    }
    printf("\n");
}

void sortAndPrintArray(float arr[], int n)
{
    float sorted[MAX];
    for (int i = 0; i < n; i++)
        sorted[i] = arr[i];

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (sorted[i] > sorted[j])
            {
                float temp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = temp;
            }
        }
    }

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%f ", sorted[i]);
    }
    printf("\n");
}
		
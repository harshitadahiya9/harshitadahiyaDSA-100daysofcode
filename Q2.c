#include <stdio.h>

int main() {
    int n, pos;
    scanf("%d", &n);
    
    int arr[100005];  // Handles up to 10^5 constraint
    
    // Read array elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    scanf("%d", &pos);  // 1-based position
    
    // Check valid position (1-based)
    if(pos < 1 || pos > n) {
        printf("Invalid position\n");
        return 1;
    }
    
    // Shift elements left from position pos (convert to 0-based)
    for(int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    // Print updated array (n-1 elements)
    for(int i = 0; i < n - 1; i++) {
        printf("%d", arr[i]);
        if(i < n - 2) printf(" ");
    }
    printf("\n");
    
    return 0;
}

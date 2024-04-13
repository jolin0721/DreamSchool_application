#include <stdio.h>
#include <string.h>


int minSubsequence(char* source, char* target) {
    int source_len = strlen(source);
    int target_len = strlen(target);
    int count = 0;
    int i, j;
    int num = 0;
    int last = -1;

    for (i = 0; i < target_len; i++) {
        int included = -1; // Initialize to -1 to indicate not found
        int notinbehind = 1;

        // Find the index of the current target character in the source string
        for (j = 0; j < source_len; j++) {
            if (target[i] == source[j]) {
                included = j;
                num += 1;
                break;
            }
        }

        // If the character is not found in the source string, return -1
        if (included == -1) {
            return -1;
        }

        // Check if the character is not behind the last occurrence
        if (included > last) {
            notinbehind = 0;
            last = included;
        }

        // If the character is not behind the last occurrence, increment count
        if (notinbehind == 1 || (notinbehind==0 && i==target_len-1)) {
            count += 1;
            num = 0;
        }
    }
    return count;
}

int main() {
    char source1[] = "abc";
    char target1[] = "acbacb";
    printf("%d\n", minSubsequence(source1, target1));

    return 0;
}

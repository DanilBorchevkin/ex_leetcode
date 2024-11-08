#include <string.h>
#include <stdio.h>

char* longestCommonPrefix(char strs[][200], int strsSize) {
    // Iterate over chars only in first string
    for (int idx = 0; idx < strlen(strs[0]); idx++) {
        int similar = 0;

        for (int word = 0; word < (strsSize - 1); word++) {
            if (strs[word + 1][idx] == '\0') {
                break;
            }
            if (strs[word][idx] == strs[word + 1][idx]) {
                similar++;
            }
        }

        if ((similar + 1) != strsSize) {
            strs[0][idx] = '\0';
            break;
        } 
    }

    return strs[0];
}

int main() {
    char testcase[200][200] = {"flower", "flow", "flight"};

    char * answer = longestCommonPrefix(testcase, 3);

    printf("\nLongest part is <%s>\n\n", answer);

    return 0;
}
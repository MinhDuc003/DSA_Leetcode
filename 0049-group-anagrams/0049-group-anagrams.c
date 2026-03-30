/*
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void* a, const void* b) { return (*(char*)a - *(char*)b); }
void sortStr(char* s) { qsort(s, strlen(s), sizeof(char), cmp); }
char*** groupAnagrams(char** strs, int strsSize, int* returnSize,int** returnColumnSizes) {
    char*** result = malloc(sizeof(char**) * strsSize);

    *returnColumnSizes = malloc(sizeof(int) * strsSize);

    char** sorted = malloc(sizeof(char*) * strsSize);

    int* used = calloc(strsSize, sizeof(int));

    for (int i = 0; i < strsSize; i++) {
        sorted[i] = strdup(strs[i]);
        sortStr(sorted[i]);
    }
    int group = 0;
    for (int i = 0; i < strsSize; i++) {
        if (used[i])
            continue;
        result[group] = malloc(sizeof(char*) * strsSize);
        int count = 0;
        for (int j = i; j < strsSize; j++) {
            if (!used[j] && strcmp(sorted[i], sorted[j]) == 0) {
                result[group][count++] = strs[j];
                used[j] = 1;
            }
        }
        (*returnColumnSizes)[group] = count;
        group++;
    }
    *returnSize = group;
    return result;
}
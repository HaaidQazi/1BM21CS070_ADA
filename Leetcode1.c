char* mergeAlternately(char* word1, char* word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int mergedLen = len1 + len2;

  
    char* merged = (char*)malloc((mergedLen + 1) * sizeof(char));
 
    int i = 0, j = 0, k = 0;
    while (i < len1 && j < len2) {
        merged[k++] = word1[i++];
        merged[k++] = word2[j++];
    }

    
    while (i < len1) {
        merged[k++] = word1[i++];
    }

    while (j < len2) {
        merged[k++] = word2[j++];
    }

    merged[k] = '\0';

    return merged;
}

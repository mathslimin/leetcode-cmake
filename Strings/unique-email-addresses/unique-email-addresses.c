#include "uthash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* key;
    UT_hash_handle hh;
} HashItem;

int numUniqueEmails(char** emails, int emailsSize)
{
    HashItem* emailSet = NULL;
    for (int i = 0; i < emailsSize; i++) {
        char local[101];
        int pos = 0;
        for (int j = 0; emails[i][j] != 0; j++) {
            if (emails[i][j] == '+' || emails[i][j] == '@') {
                break;
            }
            if (emails[i][j] != '.') {
                local[pos++] = emails[i][j];
            }
        }
        sprintf(local + pos, "%s", strchr(emails[i], '@'));
        HashItem* pEntry = NULL;
        HASH_FIND_STR(emailSet, local, pEntry);
        if (NULL == pEntry) {
            pEntry = (HashItem*)malloc(sizeof(HashItem));
            pEntry->key = (char*)malloc(sizeof(char) * (strlen(local) + 1));
            strcpy(pEntry->key, local);
            HASH_ADD_STR(emailSet, key, pEntry);
        }
    }
    return HASH_COUNT(emailSet);
}

int main()
{
    // the point array to stand for the string of array.
    char* emails[] = {
        "test.email+alex@leetcode.com", "test.e.mail+bob.cathy@leetcode.com", "testemail+david@lee.tcode.com"};

    int num;
    int count;
    num = sizeof(emails) / sizeof(emails[0]);

    count = numUniqueEmails(emails, num);
    printf("unique email answer is %d\n", count);
    return 0;
}

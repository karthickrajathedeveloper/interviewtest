#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

char s[MAX_LEN + 1]; // input string
int x, y; // values for operations
int dp[MAX_LEN + 1]; // dynamic programming array

int max(int a, int b) {
  return a > b ? a : b;
}

int main() {
  scanf("%s %d %d", s, &x, &y);

  int n = strlen(s);
  int i, j;

  // initialize dynamic programming array
  for (i = 0; i < n; i++) {
    dp[i] = 0;
  }

  // perform dynamic programming
  for (i = n - 1; i >= 0; i--) {
    // case 1: remove "ab"
    if (i < n - 1 && s[i] == 'a' && s[i + 1] == 'b') {
      dp[i] = max(dp[i], x + dp[i + 2]);
    }
    // case 2: remove "ba"
    if (i < n - 1 && s[i] == 'b' && s[i + 1] == 'a') {
      dp[i] = max(dp[i], y + dp[i + 2]);
    }
    // case 3: remove "aba" or "bab"
    if (i < n - 2 && ((s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'a') || (s[i] == 'b' && s[i + 1] == 'a' && s[i + 2] == 'b'))) {
      dp[i] = max(dp[i], x + y + dp[i + 3]);
    }
    // case 4: remove "aaa" or "bbb"
    if (i < n - 2 && ((s[i] == 'a' && s[i + 1] == 'a' && s[i + 2] == 'a') || (s[i] == 'b' && s[i + 1] == 'b' && s[i + 2] == 'b'))) {
      dp[i] = max(dp[i], x * y + dp[i + 3]);
    }
    // case 5: don't remove anything
    dp[i] = max(dp[i], dp[i + 1]);
  }

  printf("%d\n", dp[0]);

  return 0;
}

#include <stdio.h>
#include <math.h>

void iterativeHanoi(int n, char source, char middle, char destination) {
    int moves = pow(2, n) - 1;
    char s = source, m = middle, d = destination;
    if (n % 2 == 0) {
        char temp = d;
        d = m;
        m = temp;
    }
    for (int i = 1; i <= moves; i++) {
        int disk;
        char from, to;
        if (i % 3 == 1) {
            from = s; to = d;
        } else if (i % 3 == 2) {
            from = s; to = m;
        } else {
            from = m; to = d;
        }
        int pos = i & (i - 1);
        disk = 0;
        while (pos) {
            pos >>= 1;
            disk++;
        }
        disk++;
        if (n % 2 == 0 && (i % 3 == 1 || i % 3 == 3)) {
            char temp = to;
            to = from;
            from = temp;
        }
        printf("Move disk %d from %c to %c\n", disk, from, to);
    }
}

int main() {
    int n = 3;
    iterativeHanoi(n, 'A', 'B', 'C');
    return 0;
}

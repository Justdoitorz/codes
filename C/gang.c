#include <stdio.h>


struct BANG {
    int total_call;
    int people;
    int members[26];
};

struct badman {
    int call;
    int Bidx;
};

struct BANG black[27];
struct badman kbz[26];

int find_nouse(int name1, int name2)
{
    int i;
    for (i = 1; i < 27; i++) {
        if (black[i].people == 0) {
            black[i].people = 2;
            black[i].members[0] = name1;
            black[i].members[1] = name2;
            return i;
        }
    }
    return 0;
}
int gc_org(int one, int two)
{
    int i, gc = one;
    if (black[one].people > black[two].people) {
        gc = two;
    }
    for (i = 0; i < black[gc].people; i++) {
        kbz[black[gc].members[i]].Bidx = one+two-gc;
        black[one+two-gc].members[black[one+two-gc].people+i] = black[gc].members[i];
    }
    black[one+two-gc].total_call += black[gc].total_call;
    black[one+two-gc].people += black[gc].people;

    black[gc].total_call = 0;
    black[gc].people = 0;
    return one+two-gc;
}

int find_org(int one, int two, int name1, int name2)
{
    //printf("%d , %d\n", one, two);
    if (one == 0 && two == 0) {
        return find_nouse(name1, name2);
    } else if (one == two) {
        return one;
    } else if (one && two) {
        return gc_org(one, two);
    } else {
        black[one + two].members[black[one + two].people ++] = one ? name2 : name1;
        return one + two;
    }
}

int main()
{
    int i, j, N, K, minute, cnt = 0, result[26] = {0}, max;

    char one[8], two[8];

    scanf("%d%d", &N, &K);

    for (i = 0; i < N; i++) {
        scanf("%s%s%d", one, two, &minute);
        int Bidx = find_org(kbz[one[0]-'A'].Bidx, kbz[two[0]-'A'].Bidx, one[0]-'A', two[0]-'A');
        kbz[one[0]-'A'].Bidx = Bidx;
        kbz[one[0]-'A'].call += minute;
        kbz[two[0]-'A'].Bidx = Bidx;
        kbz[two[0]-'A'].call += minute;
        black[Bidx].total_call += minute;
    }

    for (i = 1; i < 27; i++) {
        if (black[i].people > 2 && black[i].total_call > K) {
            max = black[i].members[0];
            for (j = 1; j < black[i].people; j++) {
                if (kbz[max].call < kbz[black[i].members[j]].call) {
                    max = black[i].members[j];
                }
            }
            cnt ++;
            result[max] = 1;
            //printf("max = %d\n", max);
        }
    }

    printf("%d\n", cnt);
    for (i = 0; i < 26; i++) {
        if (result[i]) {
            printf("%c%c%c %d\n", i+'A', i+'A', i+'A', black[kbz[i].Bidx].people);
        }
    }


    return 0;
}

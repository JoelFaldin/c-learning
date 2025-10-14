#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    } else {
        return 0;
    }
}

void afree(char *p)
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE) {
        allocp = p;
    }
}

int main()
{
    char *p1 = alloc(100);
    char *p2 = alloc(200);

    afree(p2);
    afree(p1);

    // Stack: last in, first out

    // Incorrect:
    // afree(p1);
    // afree(p2);
}
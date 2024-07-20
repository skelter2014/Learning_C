#include <stdio.h>
#include <unistd.h>

int main(void)
{
    printf("You'll see this immediately.\nNow count slowly to 5\n");
    printf("  this will appear after 5 seconds...");
    sleep(5);
    printf(" when the buffer is finally flushed.\n");
}
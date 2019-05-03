#include "utils.h"
#include <string.h>
#include <errno.h>

int main()
{
    FILE *fp;
    fp = fopen("/home/wang/learn/myGithub/HOW_TO_DEBUG_INFO/log", "a");
    int errNum = 0;
    if(fp == NULL)
    {
	errNum = errno;
	printf("%s\n", strerror(errNum));
    }
    cfprintf(sRED, fp, "Red info means errors\n");
    cfprintf(sGREEN, fp, "Green info means OK\n");
    cfprintf(sYELLOW, fp, "Yellow info means warnings\n");
    cfprintf(sGREEN, fp, "Today is %s\n", __DATE__);
    fclose(fp);
    return 0;
}

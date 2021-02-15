#include<stdio.h>
int main()
{
#if _STDC_==0 // test for ansi c compliance
printf("cc is not ANSI C compliant");
#else
printf(“%s compiled at %s:%s.This statement is at line %d\n”,
_FILE_ , _DATE_ , _TIME_ , _LINE_);
#endif
return 0;
}
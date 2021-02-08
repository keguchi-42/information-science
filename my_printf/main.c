#include "ft_printf.h"

int main(void)
{
	ft_printf("%s is sample.\n", "this");
	ft_printf("%s%d %s%s%cレポート", "FE", 124, "情報", "科学", 'A');
	return 0;
}
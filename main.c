#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"

int main(void)
{
	int n;

	printf("Test 1\n");
	n = ft_printf("%5.3s\n", "abcdefgkl");
	printf("%d\n", n);
	n = printf("%5.3s\n", "abcdefgkl");
	printf("%d\n", n);

	printf("Test 2\n");
	n = ft_printf("%.5s\n", NULL);
	printf("%d\n", n);
	n = printf("%.5s\n", NULL);
	printf("%d\n", n);

	printf("Test 3\n");
	n = ft_printf("%-5.3s\n", "abcdefgkl");
	printf("%d\n", n);
	n = printf("%-5.3s\n", "abcdefgkl");
	printf("%d\n", n);

	printf("Test 4\n");
	n = ft_printf("%.s\n", "abcdefgkl");
	printf("%d\n", n);
	n = printf("%.s\n", "abcdefgkl");
	printf("%d\n", n);

	printf("Test 5\n");
	n = ft_printf("char : %c, str : %s, pointer : %5p, number : %d, unumber : %u, hex : %x, #hex : %7x, space : |%    d|, plus : %+d, min_width : |%-5%|",
				  'a',
				  "Yo 42 !",
				  0,
				  -100,
				  -5,
				  -1,
				  3735929054,
				  64,
				  +2,
				  42);
	printf("\n%d\n", n);
	n = printf("char : %c, str : %s, pointer : %5p, number : %d, unumber : %u, hex : %x, #hex : %7x, space : |%    d|, plus : %+d, min_width : |%-5%|",
			   'a',
			   "Yo 42 !",
			   0,
			   -100,
			   -5,
			   -1,
			   3735929054,
			   64,
			   +2,
			   42);
	printf("\n%d\n", n);
	
	printf("Test 6\n");
	n = ft_printf(", string precision : %5s, num precision : %0014.2x",
				  "-42",
				  -1);
	printf("\n%d\n", n);
	n = printf(", string precision : %5s, num precision : %0014.2x",
			   "-42",
			   -1);
	printf("\n%d\n", n);

	printf("Test 7\n");
	n = ft_printf("\n%020.19x", 8000);
	printf("\n%d\n", n);
	n = printf("\n%020.19x", 8000);
	printf("\n%d\n", n);

	printf("Test 8\n");
	n = ft_printf("\n%0014.2x %020x %00020.x %000.5x", -1, 3, 30, -1);
	printf("\n%d\n", n);
	n = printf("\n%0014.2x %020x %00020.x %000.5x", -1, 3, 30, -1);
	printf("\n%d\n", n);

	printf("Test 9\n");
	n = ft_printf("%5.3d|\n", -2);
	printf("%d\n", n);
	n = printf("%5.3d|\n", -2);
	printf("%d\n", n);

	printf("Test 10\n");
	n = ft_printf("%- 08d|\n", 2);
	printf("%d\n", n);
	n = printf("%- 08d|\n", 2);
	printf("%d\n", n);

	printf("Test 11\n");
	n = ft_printf("%- 09.8d|\n", 2);
	printf("%d\n", n);
	n = printf("%- 09.8d|\n", 2);
	printf("%d\n", n);

	printf("Test 12\n");
	n = ft_printf("%.8d|\n", -2);
	printf("%d\n", n);
	n = printf("%.8d|\n", -2);
	printf("%d\n", n);

	printf("Test 13\n");
	n = ft_printf("%8.d|\n", 0);
	printf("%d\n", n);
	n = printf("%8.d|\n", 0);
	printf("%d\n", n);

	printf("Test 14\n");
	n = ft_printf("%.8d|\n", 0);
	printf("%d\n", n);
	n = printf("%.8d|\n", 0);
	printf("%d\n", n);

	printf("Test 15\n");
	n = ft_printf("%08.5d|\n", 2);
	printf("%d\n", n);
	n = printf("%08.5d|\n", 2);
	printf("%d\n", n);

	printf("Test 16\n");
	n = ft_printf("%-8.5d|\n", 2);
	printf("%d\n", n);
	n = printf("%-8.5d|\n", 2);
	printf("%d\n", n);

	printf("Test 17\n");
	n = ft_printf("% 8d|\n", 2);
	printf("%d\n", n);
	n = printf("% 8d|\n", 2);
	printf("%d\n", n);

	printf("Test 18\n");
	n = ft_printf("% .d|\n", 2);
	printf("%d\n", n);
	n = printf("% .d|\n", 2);
	printf("%d\n", n);
	n = ft_printf("%.d|\n", 0);
	printf("%d\n", n);
	n = printf("%.d|\n", 0);
	printf("%d\n", n);

	printf("Test 19\n");
	n = ft_printf("%.1d|\n", 0);
	printf("%d\n", n);
	n = printf("%.1d|\n", 0);
	printf("%d\n", n);

	printf("Test 20\n");
	n = ft_printf("%08d|\n", 2);
	printf("%d\n", n);
	n = printf("%08d|\n", 2);
	printf("%d\n", n);

	printf("Test 21\n");
	n = ft_printf("%09.8d|\n", 2);
	printf("%d\n", n);
	n = printf("%09.8d|\n", 2);
	printf("%d\n", n);

	printf("Test 22\n");
	n = ft_printf("%-3d|", 1);
	printf("%d\n", n);
	n = printf("%-3d|", 1);
	printf("%d\n", n);

	printf("Test 23\n");
	n = ft_printf("%-5.0i|", 0);
	printf("%d\n", n);
	n = printf("%-5.0i|", 0);
	printf("%d\n", n);

	printf("Test 24\n");
	n = ft_printf("%-15p|\n", NULL);
	printf("%d\n", n);
	n = printf("%-15p|\n", NULL);
	printf("%d\n", n);

	printf("Test 25\n");
	n = ft_printf("%15p|\n", NULL);
	printf("%d\n", n);
	n = printf("%15p|\n", NULL);
	printf("%d\n", n);

	printf("Test 26\n");
	n = ft_printf("%08i|", 0);
	printf("%d\n", n);
	n = printf("%08i|", 0);
	printf("%d\n", n);

	printf("Test 27\n");
	n = ft_printf("%#x|", 0);
	printf("%d\n", n);
	n = printf("%#x|", 0);
	printf("%d\n", n);

	printf("Test 28\n");
	n = ft_printf("%#x|", 2);
	printf("%d\n", n);
	n = printf("%#x|", 2);
	printf("%d\n", n);

	printf("Test 28\n");
	n = ft_printf("%#.3x|", 3);
	printf("%d\n", n);
	n = printf("%#.3x|", 3);
	printf("%d\n", n);

	printf("Test 29\n");
	n = ft_printf("%+#.3x|", 3);
	printf("%d\n", n);
	n = printf("%+#.3x|", 3);
	printf("%d\n", n);

	printf("Test 30\n");
	n = ft_printf("%+x|", 3);
	printf("%d\n", n);
	n = printf("%+x|", 3);
	printf("%d\n", n);

	printf("Test 31\n");
	n = ft_printf("% x|", 3);
	printf("%d\n", n);
	n = printf("% x|", 3);
	printf("%d\n", n);

	printf("Test 32\n");
	n = ft_printf("%+#.3u|", 3);
	printf("%d\n", n);
	n = printf("%+#.3u|", 3);
	printf("%d\n", n);

	printf("Test 33\n");
	n = ft_printf("%+u|", 3);
	printf("%d\n", n);
	n = printf("%+u|", 3);
	printf("%d\n", n);

	printf("Test 34\n");
	n = ft_printf("% u|", 3);
	printf("%d\n", n);
	n = printf("% u|", 3);
	printf("%d\n", n);
}

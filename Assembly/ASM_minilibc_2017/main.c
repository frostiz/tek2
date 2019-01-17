#include <stdio.h>
#include <stdlib.h>

char	*strchr(char *, int);
size_t	strlen(const char *);
void	*memset(void *, int, size_t);
void	*memcpy(void *, void *, size_t);
int	strcmp(const char *, const char *);
int	strncmp(const char *, const char *, size_t);
int	strcasecmp(const char *, const char *);
char	*rindex(const char *, int);
char	*strstr(const char *, const char *);
char	*strpbrk(const char *, const char *);

void	test_strlen()
{
	printf("testing strlen\n");
	printf(" - expect [3] - got [%d]\n", strlen("abc"));
	printf(" - expect [1] - got [%d]\n", strlen("a"));
	printf(" - expect [0] - got [%d]\n", strlen(""));
}

void	test_strchr()
{
	printf("testing strchr\n");
	printf(" - expect [bc] - got [%s]\n", strchr("abc", 'b'));
	printf(" - expect [tyuiop] - got [%s]\n", strchr("azertyuiop", 't'));
	printf(" - expect [NULL] - got [%s]\n", strchr("kokoko", 'a'));
	printf(" - expect [NULL] - got [%s]\n", strchr(NULL, 'b'));
}

void	test_memset()
{
	void	*addr;

	addr = malloc(42);
	sprintf(addr, "default value");
	printf("testing memset\n");
	printf(" - expect [a] - got [%s]\n", (char *)memset(addr, 'a', 1));
	printf(" - expect [b] - got [%s]\n", (char *)memset(addr, 'b', 1));
	printf(" - expect [c] - got [%s]\n", (char *)memset(addr, 'c', 1));
	printf(" - expect [bbb] - got [%s]\n", (char *)memset(addr, 'b', 3));
	printf(" - expect [dddd] - got [%s]\n", (char *)memset(addr, 'd', 4));
	printf(" - expect [NULL] - got [%s]\n", (char *)memset(NULL, 'b', 3));
}

void	test_memcpy()
{
	void	*dest = malloc(50);
	void	*src = malloc(50);

	printf("testing memcpy\n");
	sprintf(dest, "destination");
	sprintf(src, "source");
	printf(" - expect [soutination] - got [%s]\n", (char *)memcpy(dest, src, 3));
	sprintf(dest, "destination");
	sprintf(src, "source");
	printf(" - expect [sourcnation] - got [%s]\n", (char *)memcpy(dest, src, 5));
	sprintf(dest, "destination");
	sprintf(src, "source");
	printf(" - expect [sourceation] - got [%s]\n", (char *)memcpy(dest, src, 6));
	sprintf(dest, "destination");
	sprintf(src, "source");
	/*printf(" - expect [destination] - got [%s]\n", (char *)memcpy(dest, NULL, 6));
	sprintf(dest, "destination");
	sprintf(src, "source");
	printf(" - expect [NULL] - got [%s]\n", (char *)memcpy(NULL, src, 6));*/
	
}

void	test_strcmp()
{
	printf("testing strcmp\n");
	char *a = "aaaaaaa";
	char *b = "adddddd";
	
	printf(" - expect [%d] got [%d]\n", a[1] - b[1], strcmp(a, b));
	printf(" - expect [%d] got [%d]\n", b[1] - a[1], strcmp(b, a));
	printf(" - expect [%d] got [%d]\n", a[1] - a[1], strcmp(a, a));

	char *c = "pipi";
	char *d = "caca";
	printf("%d\n\n", strcmp("yoyo", "yoyo"));
	printf("%d\n", strcmp("yoyo", "yo"));
	printf("%d\n", strcmp("yo", "yoyo"));
	printf("%d\n", strcmp(c, d));
	printf("%d\n", strcmp(d, c));
}

void	test_strncmp()
{
	printf("testing strncmp\n");
	char *a = "aaaaaa";
	char *b = "aaaad";
	
	printf(" - expect [%d] got [%d]\n", 0, strncmp(a, b, 3));
	printf(" - expect [%d] got [%d]\n", 3, strncmp(b, a, 5));
	printf(" - expect [%d] got [%d]\n", 0, strncmp(a, a, 7));
}

void	test_strcasecmp()
{
	printf("testing strcasecmp\n");
	char *a = "Aaa";
	char *b = "aac";
	
	printf(" - expect [%d] got [%d]\n", -2, strcasecmp(a, b));
	printf(" - expect [%d] got [%d]\n", 2, strcasecmp(b, a));
	printf(" - expect [%d] got [%d]\n", 0, strcasecmp(a, a));
}

void	test_rindex()
{
	printf("testing rindex\n");

	printf(" - expect [%s] got [%s]\n", "a", rindex("caca", 'a'));
	printf(" - expect [%s] got [%s]\n", "aci", rindex("caci", 'a'));
	printf(" - expect [%s] got [%s]\n", "NULL", rindex("cfefef", 'a'));
	printf(" - expect [%s] got [%s]\n", "ki", rindex("kokikokikoki", 'k'));
}

void	test_strstr()
{
	printf("testing strstr\n");

	printf(" - expect [%s] got [%s]\n", "abcdef", strstr("abcdef", "abc"));
	printf(" - expect [%s] got [%s]\n", "kukoki", strstr("snaosnasakukoki", "ku"));
	printf(" - expect [%s] got [%s]\n", "koka", strstr("sasasasasifrifgrkoka", "koka"));
	printf(" - expect [%s] got [%s]\n", "NULL", strstr("sasasasasifrifgrkoka", "kokak"));
	printf(" - expect [%s] got [%s]\n", "ckakekukoki", strstr("ckakekukoki", ""));
	printf(" - expect [%s] got [%s]\n", "NULL", strstr("", "ca"));
	printf(" - expect [%s] got [%s]\n", "NULL", strstr("", ""));
}

void	test_strpbrk()
{
	printf("testing strpbrk\n");

	printf(" - expect [%s] got [%s]\n", "uis une chaine", strpbrk("je suis une chaine", "pmlku"));
}

int	main()
{
	test_strlen();
	test_strchr();
	test_memset();
	test_memcpy();
	test_strcmp();
	test_strncmp();
	test_strcasecmp();
	test_rindex();
	test_strstr();
	test_strpbrk();
	return (0);
}

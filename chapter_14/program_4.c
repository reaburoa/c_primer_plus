#include <stdio.h>
#include <string.h>

#define MAX 40

struct names {
	char name[MAX];
	char mid[MAX];
	char last[MAX];
};

typedef struct member {
	int s_no;
	struct names s_name;
} s_member;

void display_members(const s_member ss[], int n);
void display_m(const s_member *ss);

void display_members(const s_member ss[], int n)
{
	int i = 0;
	for (i = 0; i < n; i ++)
	{
		printf("%s, %s ", ss[i].s_name.name, ss[i].s_name.last);
		if (ss[i].s_name.mid[0] != '\0')
			printf("%c. ", ss[i].s_name.mid[0]);
		printf("-- %d\n", ss[i].s_no);
	}
}

void display_m(const s_member *ss)
{
	printf("%s, %s ", ss->s_name.name, ss->s_name.last);
	if (ss->s_name.mid[0] != '\0')
		printf("%c. ", ss->s_name.mid[0]);
	printf("-- %d\n", ss->s_no);
}

int main(void)
{
	s_member members[5] = {
		{1, {"san", "", "zhang"}},
		{2, {"si", "zhong", "li"}},
		{3, {"wu", "z", "wang"}},
		{4, {"liu", "s", "sun"}},
		{5, {"seven", "e", "zhao"}},
	};
	printf("display struct by value:\n");
	display_members(members, 5);
	int i = 0;
	printf("display by pointer:\n");
	for (i = 0; i < 5; i ++)
		display_m(&members[i]);
	return 0;
}

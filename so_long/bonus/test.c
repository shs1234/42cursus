#include <dirent.h>
#include <stdio.h>
#include <string.h>

int	main(void)
{
	DIR				*d;
	struct dirent	*dir;

	d = opendir("./imgs/player");
	if (d)
	{
		while ((dir = readdir(d)) != NULL)
		{
			// 파일 이름이 "."나 ".."으로 시작하는 경우, 처리하지 않음
			if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0)
				continue ;
			printf("%s\n", dir->d_name);
		}
		closedir(d);
	}
	return (0);
}

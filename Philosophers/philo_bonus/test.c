#include <fcntl.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	sem_t	*sem;

	const char *semaphore_name = "/my_semaphore"; // 세마포어 이름
	// 세마포어 생성
	sem = sem_open(semaphore_name, O_CREAT | O_EXCL, 0644, 1);
	if (sem == SEM_FAILED)
	{
		perror("sem_open");
		exit(EXIT_FAILURE);
	}
	// 세마포어 값 증가
	sem_post(sem);
	// 세마포어 값 감소
	sem_wait(sem);
	// 세마포어 닫기
	sleep(10);
	if (sem_close(sem) == -1)
	{
		perror("sem_close");
		exit(EXIT_FAILURE);
	}
	// 세마포어 삭제
	if (sem_unlink(semaphore_name) == -1)
	{
		perror("sem_unlink");
		exit(EXIT_FAILURE);
	}
	return (0);
}

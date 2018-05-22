/*
** EPITECH PROJECT, 2018
** my_exec
** File description:
** ctrl
*/

#include "42.h"

void	*thread_ctrl(void *arg)
{
	while (1) {

	}
}

void	ctrl_catcher(char sig)
{
	pthread_t	ctrl_catcher_thread;

	pthread_create(&ctrl_catcher_thread, NULL, thread_ctrl, NULL);
	pthread_join(ctrl_catcher_thread, NULL);
	if (sig && sig == 0x0C)
		printf("ctrl l !\n");
}
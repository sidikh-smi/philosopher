#include "philo.h"

void    eat(t_philo *philo)
{
    pthread_mutex_lock(&philo->forks[philo->index]);
    ft_printing("has taken a fork", philo);
    pthread_mutex_lock(&philo->forks[(philo->index + 1) 
        % philo->data->nmbr_philo]);
    ft_printing("has taken a fork", philo);
	pthread_mutex_lock(&philo->data->check_eat);
    ft_printing("is eating", philo);
    philo->eat = 1;
    philo->last_eat = time_now();
    philo->nmbr_eat++;
	pthread_mutex_unlock(&philo->data->check_eat);
    ft_sleep(philo->data->time_eat * 1000);
    philo->eat = 0;
    pthread_mutex_unlock(&philo->forks[philo->index]);
    pthread_mutex_unlock(&philo->forks[(philo->index + 1) 
        % philo->data->nmbr_philo]);
}

void    sleepng(t_philo *philo)
{
    ft_printing("is sleeping", philo);
    ft_sleep(philo->data->time_sleep * 1000);
}

int	finish_eat(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->nmbr_philo)
	{
		if (philo[i].nmbr_eat < philo->data->nmbr_time_eat)
			return (0);
		i++;
	}
	return (1);
}

void	death(t_philo *philo)
{
	t_data	*data;
	int		i;

	data = philo->data;
	i = 0;
	while (1)
	{
		while (i < philo->data->nmbr_philo)
		{
			pthread_mutex_lock(&philo[i].data->check_eat);
			pthread_mutex_lock(&philo[i].data->eat);
			if (time_now() - philo[i].last_eat >= data->time_die
				&& !philo[i].eat)
			{
				data->die = 1;
				pthread_mutex_lock(&philo[i].data->printing);
				printf("%ld		Philo Number	%d		Died \n",
					(time_now() - philo->start), philo->index + 1);
				return ;
			}
			pthread_mutex_unlock(&philo[i].data->check_eat);
			pthread_mutex_unlock(&philo[i].data->eat);
			i++;
		}
		pthread_mutex_lock(&philo->data->check_eat);
		if (data->nmbr_time_eat != -1 && finish_eat(philo))
			return ;
		pthread_mutex_unlock(&philo->data->check_eat);
	}
}
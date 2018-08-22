#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "program_4_queue.h"

#define MIN_PER_HR 60.0

#define QUEUE_NUMS 3

bool newcustomer(double x);
Item customertime(long when);

int main(void)
{
	Queue line[QUEUE_NUMS];
	Item temp;
	int hours;
	int perhour;
	long cycle, cyclelimit;
	long turnaways = 0;
	long customers = 0;
	long served = 0;
	long ar_served[QUEUE_NUMS];
	long sum_line = 0;
	int wait_time[QUEUE_NUMS];
	double min_per_cust;
	long line_wait = 0;
	long each_line_wait[QUEUE_NUMS];
	int q_i = 0;
	for (q_i = 0; q_i < QUEUE_NUMS; q_i ++)
	{
		InitializeQueue(&line[q_i]);
		wait_time[q_i] = 0;
		ar_served[q_i] = 0;	
		each_line_wait[q_i] = 0;
	}
	srand((unsigned int)time(0));
	puts("Case Study:Sigmund Lander's Advice Booth");
	puts("Enter the number of simulation hours:");
	scanf("%d", &hours);
	cyclelimit = MIN_PER_HR * hours;
	puts("Enter the average number of customers per hour:");
	scanf("%d", &perhour);
	min_per_cust = MIN_PER_HR / perhour;
	for (cycle = 0; cycle < cyclelimit; cycle ++)
	{
		int full_q = 0;
		int min_items = 0;
		int min_q_index = 0;
		for (q_i = 0; q_i < QUEUE_NUMS; q_i ++)
		{
			if (min_items >= QueueItemCount(&line[q_i]))
			{
				min_items = line[q_i].items;
				min_q_index = q_i;
			}
		}
		if (newcustomer(min_per_cust))
		{
			if (QueueIsFull(&line[min_q_index]))
				turnaways ++;
			else
			{
				customers ++;
				temp = customertime(cycle);
				EnQueue(temp, &line[min_q_index]);
			}
		}
		for (q_i = 0; q_i < QUEUE_NUMS;	q_i ++)
		{
			if (wait_time[q_i] <= 0 && !QueueIsEmpty(&line[q_i]))
			{
				DeQueue(&temp, &line[q_i]);
				wait_time[q_i] = temp.processtime;
				each_line_wait[q_i] += cycle - temp.arrive;
				line_wait += cycle - temp.arrive;
				ar_served[q_i] ++;
				served ++;
			}
			if (wait_time[q_i] > 0)
				wait_time[q_i] --;
			sum_line += QueueItemCount(&line[q_i]);
		}
	}
	if (customers > 0)
	{
		printf("Customers accepted:%ld\n", customers);
		printf("Customers served:%ld\n", served);
		printf("Turnaways:%ld\n", turnaways);
		printf("Average queue size: %.2f\n", (double)sum_line / cyclelimit);
		printf("Average wait time: %.2f minutes\n", (double)line_wait / served);
		printf("Each line wait time:\n");
		for (q_i = 0; q_i < QUEUE_NUMS; q_i ++)
			printf("Line %d wait time %.2f minutes, served %ld\n", (q_i + 1), (double)(each_line_wait[q_i] / ar_served[q_i]), ar_served[q_i]);
	}
	else
		puts("No customers!");

	for (q_i = 0; q_i < QUEUE_NUMS; q_i ++)
		EmptyTheQueue(&line[q_i]);
	puts("Bye!");

	return 0;
}

bool newcustomer(double x)
{
	if (rand() * x / RAND_MAX < 1)
		return true;
	else
		return false;
}

Item customertime(long when)
{
	Item cust;
	cust.processtime = rand() % 3 + 1;
	cust.arrive = when;

	return cust;
}


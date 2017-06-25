#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "longint.h"
#include <sys/types.h>
#include <unistd.h>


//1 Specjalistas, pagydo / Apylinkes, sveikas
//2 Specjalistas, pasiuncia / Apylinkes, nesveikas

void main()
{
	const int timeOfLocDoctor = 5;
	const int timeOfSpecDoctor = 10;
	const int modelingTime = 1000;
	const int numOfSpecDoctors1 = 10;
    const int numOfLocDoctors2 = 3;
	const int numOfSpecDoctors2 = 4;

	srand(getpid());

	int time = 0, tempTime = 0, finalTime1 = 0, finalTime2 = 0, timeOfProc1[numOfSpecDoctors1], timeOfProc2[numOfLocDoctors2], timeOfProc2_1[numOfSpecDoctors2];
	int patient = 0, numOfServedPatients1 = 0, numOfServedPatients2 = 0;
	int i = 0, random = 0;
	char *it = "0";

	STRUCTURE *specDoctorQueues1[numOfSpecDoctors1];
	STRUCTURE *locDoctorQueues2[numOfLocDoctors2];
	STRUCTURE *specDoctorQueues2[numOfSpecDoctors2];
	list *iterator, *one;

	iterator = Read(it);
	it = "1";
	one = Read(it);

	while(i < numOfSpecDoctors1)
	{
		specDoctorQueues1[i] = create();
		timeOfProc1[i] = timeOfSpecDoctor;
		it = Sum(iterator, one);
		i = atoi(it);
		iterator = Read(it);
	}

	it = "0";
	iterator = Read(it);
	i = 0;

	while(i < numOfLocDoctors2)
	{
		locDoctorQueues2[i] = create();
		timeOfProc2[i] = timeOfLocDoctor;
		it = Sum(iterator, one);
		i = atoi(it);
		iterator = Read(it);
	}

	it = "0";
	iterator = Read(it);
	i = 0;

	while(i < numOfSpecDoctors2)
	{
		specDoctorQueues2[i] = create();
		timeOfProc2_1[i] = timeOfSpecDoctor;
		it = Sum(iterator, one);
		i = atoi(it);
		iterator = Read(it);
	}

	for(time = 0; time < modelingTime; time++)
	{
		patient = rand() % 3;
		if(patient == 1)
		{
			random = rand() % numOfSpecDoctors1;
			enqueue(1, &specDoctorQueues1[random]);	
			random = rand() % numOfLocDoctors2;
			enqueue(1, &locDoctorQueues2[random]);
		}
		if(patient == 2)
		{
			random = rand() % numOfSpecDoctors1;
			enqueue(2, &specDoctorQueues1[random]);
			random = rand() % numOfLocDoctors2;
			enqueue(2, &locDoctorQueues2[random]);
		}

		for(i = 0 ; i < numOfSpecDoctors1; i++)
		{
			if(isEmpty(&specDoctorQueues1[i]) == 1)
			{
				timeOfProc1[i]--;
				if(timeOfProc1[i] == 0)
				{ 
					dequeue(&specDoctorQueues1[i], &patient);
					if(patient == 2)
					{
						do
						{
						random = rand() % numOfSpecDoctors1;
						} while(i == random);
						enqueue(1, &specDoctorQueues1[random]);
						timeOfProc1[i] = timeOfSpecDoctor;
					}
					else
					{
						numOfServedPatients1++;
						timeOfProc1[i] = timeOfSpecDoctor;
					}
				}
			}
		}

		for(i = 0; i < numOfLocDoctors2; i++)
		{
			if(isEmpty(&locDoctorQueues2[i]) == 1)
			{
				timeOfProc2[i]--;
				if(timeOfProc2[i] == 0)
				{
					dequeue(&locDoctorQueues2[i], &patient);
					if(patient == 2)
					{
						random = rand() % numOfSpecDoctors2;
						enqueue(1, &specDoctorQueues2[random]);
						timeOfProc2[i] = timeOfLocDoctor;
					}
					else
					{
						numOfServedPatients2++;
						timeOfProc2[i] = timeOfLocDoctor;
					}
				}
			}
		}

		for(i = 0; i < numOfSpecDoctors2; i++)
		{
			if(isEmpty(&specDoctorQueues2[i]) == 1)
			{
				timeOfProc2_1[i]--;
				if(timeOfProc2_1[i] == 0)
				{
					dequeue(&specDoctorQueues2[i], &patient);
					numOfServedPatients2++;
					timeOfProc2_1[i] = timeOfSpecDoctor;
				}
			}
		}
	}

	it = "0";
	iterator = Read(it);
	i = 0;
	while(i < numOfSpecDoctors1)
	{
		destroyQueue(&specDoctorQueues1[i]);
		it = Sum(iterator, one);
		i = atoi(it);
		iterator = Read(it);
	}
	it = "0";
	iterator = Read(it);
	i = 0;
	while(i < numOfLocDoctors2)
	{
		destroyQueue(&locDoctorQueues2[i]);
		it = Sum(iterator, one);
		i = atoi(it);
		iterator = Read(it);
	}
	it = "0";
	iterator = Read(it);
	i = 0;
	while(i < numOfSpecDoctors2)
	{
		destroyQueue(&specDoctorQueues2[i]);
		it = Sum(iterator, one);
		i = atoi(it);
		iterator = Read(it);
	}


	 deleteList(iterator);
	 deleteList(one);	

	printf("Simuliacijos laikas = %d\n", modelingTime);
	printf("PROCESAS 1\nSpecialistų skaičius = %d\nAptarnauti pacientai = %d\n", numOfSpecDoctors1, numOfServedPatients1);
	printf("PROCESAS 2\nSpecialistų skaičius = %d\nApylinkės gydytojų skaičius = %d\nAptarnauti pacientai = %d\n", numOfSpecDoctors2, numOfLocDoctors2, numOfServedPatients2);
}
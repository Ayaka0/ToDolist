#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_TASKS 100

struct Task {
	char name[50];
	int priority;
};

struct Task taskList[MAX_TASKS];
int numTasks = 0;

void addTask() {
	if (numTasks >= MAX_TASKS) {
		printf("���X�g�������ς��ł��B\n");
		return;
	}

	struct Task newTask;

	printf("�^�X�N������͂��ĉ������F");
	scanf_s("%s", newTask.name, sizeof(newTask.name));

	printf("�D��x����͂��Ă��������B�i1����10�͈̔́j:");
	scanf_s("%d", &newTask.priority, sizeof(newTask.priority));

	taskList[numTasks] = newTask;
	numTasks++;

	printf("�^�X�N���ǉ�����܂����B\n");
}

void displayTasks() {
	if (numTasks == 0) {
		printf_s("�^�X�N������܂���B\n");
		return;
	}

	printf("ToDo���X�g�F\n");
	for (int i = 0; i < numTasks; i++) {
		printf_s("�^�X�N���F%s, �D��x�F%d\n", taskList[i].name, taskList[i].priority);
	}
}

void deleteTask() {
	if (numTasks == 0) {
		printf("�^�X�N������܂���B\n");
		return;
	}

	int index;
	printf("�폜����^�X�N�̃C���f�b�N�X����͂��Ă��������i0����%d�͈̔́j�F", numTasks - 1);
	scanf_s("%d", &index);

	if (index < 0 || index >= numTasks) {
		printf("�����ȃC���f�b�N�X�ł��B\n");
		return;
	}

	for (int i = index; i < numTasks - 1; i++) {
		taskList[i] = taskList[i + 1];
	}

	numTasks--;

	printf("�^�X�N���폜����܂����B\n");
}

int main() {
	int choice;

	while (1) {
		printf("\nToDo���X�g\n");
		printf("�P�D�^�X�N��ǉ�����\n");
		printf("�Q�D�^�X�N��\��������\n");
		printf("�R�D�^�X�N���폜����\n");
		printf("�S�D�I������\n");
		printf("�I�����Ă��������F");
		scanf_s("%d", &choice);

		switch (choice) {
			case 1:
				addTask();
				break;
			case 2:
				displayTasks();
				break;
			case 3:
				deleteTask();
				break;
			case 4:
				printf("�v���O�������I�����܂��B\n");
				exit(0);
			default:
				printf("�����ȑI���ł��B\n");
		}

	}

	return 0;
}
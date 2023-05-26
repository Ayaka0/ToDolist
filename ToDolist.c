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
		printf("リストがいっぱいです。\n");
		return;
	}

	struct Task newTask;

	printf("タスク名を入力して下さい：");
	scanf_s("%s", newTask.name, sizeof(newTask.name));

	printf("優先度を入力してください。（1から10の範囲）:");
	scanf_s("%d", &newTask.priority, sizeof(newTask.priority));

	taskList[numTasks] = newTask;
	numTasks++;

	printf("タスクが追加されました。\n");
}

void displayTasks() {
	if (numTasks == 0) {
		printf_s("タスクがありません。\n");
		return;
	}

	printf("ToDoリスト：\n");
	for (int i = 0; i < numTasks; i++) {
		printf_s("タスク名：%s, 優先度：%d\n", taskList[i].name, taskList[i].priority);
	}
}

void deleteTask() {
	if (numTasks == 0) {
		printf("タスクがありません。\n");
		return;
	}

	int index;
	printf("削除するタスクのインデックスを入力してください（0から%dの範囲）：", numTasks - 1);
	scanf_s("%d", &index);

	if (index < 0 || index >= numTasks) {
		printf("無効なインデックスです。\n");
		return;
	}

	for (int i = index; i < numTasks - 1; i++) {
		taskList[i] = taskList[i + 1];
	}

	numTasks--;

	printf("タスクが削除されました。\n");
}

int main() {
	int choice;

	while (1) {
		printf("\nToDoリスト\n");
		printf("１．タスクを追加する\n");
		printf("２．タスクを表示させる\n");
		printf("３．タスクを削除する\n");
		printf("４．終了する\n");
		printf("選択してください：");
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
				printf("プログラムを終了します。\n");
				exit(0);
			default:
				printf("無効な選択です。\n");
		}

	}

	return 0;
}
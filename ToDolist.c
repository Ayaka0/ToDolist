#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100 //プログラムで管理できる最大タスク数

//タスクのデータを表す構造体 Task を定義。name メンバーは最大50文字の文字列を格納するための配列です。priority メンバーはタスクの優先度を表す整数です。
struct Task {
    char name[50];
    int priority;
};

//タスクを格納するための配列 taskList と、現在のタスク数を保持する変数 numTasks を宣言
struct Task taskList[MAX_TASKS];
int numTasks = 0;

//addTask 関数は新しいタスクを追加するための処理を行う
void addTask() {
    if (numTasks >= MAX_TASKS) {
        printf("リストがいっぱいです。\n");
        return;
    }

    struct Task newTask;

    printf("タスク名を入力してください: ");
    scanf_s("%s", newTask.name, sizeof(newTask.name) / sizeof(newTask.name[0]));


    printf("優先度を入力してください (1から10の範囲): ");
    scanf_s("%d", &newTask.priority);

    taskList[numTasks] = newTask;
    numTasks++;

    printf("タスクが追加されました。\n");
}

//displayTasks 関数は現在のタスクリストを表示するための処理
void displayTasks() {
    if (numTasks == 0) {
        printf("タスクがありません。\n");
        return;
    }

    printf("ToDoリスト:\n");
    for (int i = 0; i < numTasks; i++) {
        if (taskList[i].priority >= 8) {
            printf("\x1b[31m"); // 赤色
        }
        else if (taskList[i].priority >= 4) {
            printf("\x1b[33m"); // 黄色
        }
        else {
            printf("\x1b[32m"); // 緑色
        }

        printf("タスク名: %s, 優先度: %d\n", taskList[i].name, taskList[i].priority);
        printf("\x1b[37m"); // 白色
    }
}

//deleteTask 関数は指定したタスクを削除するための処理
void deleteTask() {
    if (numTasks == 0) {
        printf("タスクがありません。\n");
        return;
    }

    int index;
    printf("削除するタスクのインデックスを入力してください (0から%dの範囲): ", numTasks - 1);
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

    //無限ループを作成し、ユーザーが終了するまでプログラムの実行を続ける
    while (1) {
        printf("\nToDoリスト\n");
        printf("1. タスクを追加する\n");
        printf("2. タスクを表示する\n");
        printf("3. タスクを削除する\n");
        printf("4. 終了する\n");
        printf("選択してください: ");
        scanf_s("%d", &choice);  //ユーザーからの入力を受け取り、choice 変数に格納

    //choice 変数の値に応じて、各ケースの処理
        switch (choice) {
        case 1: //choice の値が 1 の場合、addTask 関数を呼び出して新しいタスクを追加
            addTask();
            break;
        case 2: //choice の値が 2 の場合、displayTasks 関数を呼び出して現在のタスクリストを表示
            displayTasks();
            break;
        case 3: //choice の値が 3 の場合、deleteTask 関数を呼び出して指定したタスクを削除
            deleteTask();
            break;
        case 4: //choice の値が 4 の場合、プログラムを終了
            printf("プログラムを終了します。\n");
            exit(0);
        default: //choice の値が 1, 2, 3, 4 以外の場合、無効な選択であることをユーザーに通知
            printf("無効な選択です。\n");
        }
    }

    return 0;
}

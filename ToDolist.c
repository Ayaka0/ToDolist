#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100 //�v���O�����ŊǗ��ł���ő�^�X�N��

//�^�X�N�̃f�[�^��\���\���� Task ���`�Bname �����o�[�͍ő�50�����̕�������i�[���邽�߂̔z��ł��Bpriority �����o�[�̓^�X�N�̗D��x��\�������ł��B
struct Task {
    char name[50];
    int priority;
};

//�^�X�N���i�[���邽�߂̔z�� taskList �ƁA���݂̃^�X�N����ێ�����ϐ� numTasks ��錾
struct Task taskList[MAX_TASKS];
int numTasks = 0;

//addTask �֐��͐V�����^�X�N��ǉ����邽�߂̏������s��
void addTask() {
    if (numTasks >= MAX_TASKS) {
        printf("���X�g�������ς��ł��B\n");
        return;
    }

    struct Task newTask;

    printf("�^�X�N������͂��Ă�������: ");
    scanf_s("%s", newTask.name, sizeof(newTask.name) / sizeof(newTask.name[0]));


    printf("�D��x����͂��Ă������� (1����10�͈̔�): ");
    scanf_s("%d", &newTask.priority);

    taskList[numTasks] = newTask;
    numTasks++;

    printf("�^�X�N���ǉ�����܂����B\n");
}

//displayTasks �֐��͌��݂̃^�X�N���X�g��\�����邽�߂̏���
void displayTasks() {
    if (numTasks == 0) {
        printf("�^�X�N������܂���B\n");
        return;
    }

    printf("ToDo���X�g:\n");
    for (int i = 0; i < numTasks; i++) {
        if (taskList[i].priority >= 8) {
            printf("\x1b[31m"); // �ԐF
        }
        else if (taskList[i].priority >= 4) {
            printf("\x1b[33m"); // ���F
        }
        else {
            printf("\x1b[32m"); // �ΐF
        }

        printf("�^�X�N��: %s, �D��x: %d\n", taskList[i].name, taskList[i].priority);
        printf("\x1b[37m"); // ���F
    }
}

//deleteTask �֐��͎w�肵���^�X�N���폜���邽�߂̏���
void deleteTask() {
    if (numTasks == 0) {
        printf("�^�X�N������܂���B\n");
        return;
    }

    int index;
    printf("�폜����^�X�N�̃C���f�b�N�X����͂��Ă������� (0����%d�͈̔�): ", numTasks - 1);
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

    //�������[�v���쐬���A���[�U�[���I������܂Ńv���O�����̎��s�𑱂���
    while (1) {
        printf("\nToDo���X�g\n");
        printf("1. �^�X�N��ǉ�����\n");
        printf("2. �^�X�N��\������\n");
        printf("3. �^�X�N���폜����\n");
        printf("4. �I������\n");
        printf("�I�����Ă�������: ");
        scanf_s("%d", &choice);  //���[�U�[����̓��͂��󂯎��Achoice �ϐ��Ɋi�[

    //choice �ϐ��̒l�ɉ����āA�e�P�[�X�̏���
        switch (choice) {
        case 1: //choice �̒l�� 1 �̏ꍇ�AaddTask �֐����Ăяo���ĐV�����^�X�N��ǉ�
            addTask();
            break;
        case 2: //choice �̒l�� 2 �̏ꍇ�AdisplayTasks �֐����Ăяo���Č��݂̃^�X�N���X�g��\��
            displayTasks();
            break;
        case 3: //choice �̒l�� 3 �̏ꍇ�AdeleteTask �֐����Ăяo���Ďw�肵���^�X�N���폜
            deleteTask();
            break;
        case 4: //choice �̒l�� 4 �̏ꍇ�A�v���O�������I��
            printf("�v���O�������I�����܂��B\n");
            exit(0);
        default: //choice �̒l�� 1, 2, 3, 4 �ȊO�̏ꍇ�A�����ȑI���ł��邱�Ƃ����[�U�[�ɒʒm
            printf("�����ȑI���ł��B\n");
        }
    }

    return 0;
}

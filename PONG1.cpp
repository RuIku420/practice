/*
------------------------------------------------------------------------------
���j
�E��l�ŗV�ׂ�PONG����낤
�E������߂Ďl�p�`�̕����ő�p���܂��@�@�@�@�@�@�@�@�@�@�@�@�@�@ �@���@�摜�\��
�E�ڂ����̈ʒu�̏������ƍŏ��̃{�[���̌����������_����������
�E�`��̍X�V�𐏎��s�����ƂŌy���Ȃ����H�@�����R�[�h���G�ŏ璷�@
�Esleep�֐����g���@
�E�o�[�̏��Ƃ��͔z���������
�E�{�[�����o�Ȃ��I�I > �o���I�I
�E�@�������ǂ�����H
------------------------------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS         //scanf�̂���

#include <stdio.h>          //������
#include <windows.h>        //getasynckeystate �Ƃ��̂���
#include <stdlib.h>         //�����_���̂���
#include <time.h>           //�����_���̂���

#define X_MAX 60 //x���̍ő�l
#define Y_MAX 23 //y���̍ő�l
#define SPEED 60 //�{�[���̑���

HANDLE hStdout;

void draw(int x, int y, const char* a) {      //���Ɓ��Ƅ��𔻒f���ĔC�ӂ̍s�A��ɕ`�悷��
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(hStdout, coord);
	printf(a);

}

void drawscore(int x, int y, int a) {      //������C�ӂ̍s�A��ɕ`�悷��
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(hStdout, coord);
	printf("%d", a);

}

int main(void) {

	//�ϐ��錾
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	
	int bar[2][3];			//�o�[�@���̐����͍�0 �E1�@�E�̐����͂��ꂼ���x�� y���@������͏����p��y��

	int ball[3];			//�{�[���@�O��x�� 1��y�� 2�̓{�[���̕���

	char z;                             //for�p �� scanf�̑ҋ@�p
	int s = 0;                         //�X�R�A����p 0�ŉ��_�Ȃ��@1�ō��ɉ��_�@2�ŉE�ɉ��_ ���_����0��
	int sc1, sc2;              //�X�R�A�\�L�p�@�{�[�����������ɑ���

	int barmove = 0;				//���u�� �O�ŋ󔒂�\���@�P�Ł���\�� s,w,o,l�������ꂽ��P�@�Ȃɂ�������ĂȂ�������O

	//������
	//int bally ;

	srand((unsigned int)time(NULL));

	


	while (1) {
		system("cls");


		printf("PONG(��l�p)\n\n");
		printf("���[��\n");
		printf("�o�[�𓮂����ă{�[���𒵂˕Ԃ��Q�[��\n\n");
		printf("������@\n");
		printf("���̃o�[�FW�ŏ�Ɉړ��@S�ŉ��Ɉړ�\n");
		printf("�E�̃o�[�FO�ŏ�Ɉړ��@L�ŉ��Ɉړ�\n\n");
		printf("�������ςȂ��ɂ���Ƃ��܂��������܂���\n");
		printf("(�����Ȃ��Ȃ����Ⴄ)\n");
		printf("��񂸂����Ă�������\n\n");
		printf("���������F�ܓ_���\n\n");
		printf("�����L�[�������Ă���G���^�[�������ƃX�^�[�g�A�v���C����Q�������Ă�߂�");
		scanf("%*s%c", &z); //%*s�ŕ���������肷�Ă�

		sc1 = 0;
		sc2 = 0;

		//�o�[�̏�����-----------------------------------------------
		bar[0][0] = 0;
		bar[0][1] = (int)(Y_MAX / 2) - 4;
		bar[1][0] = X_MAX;
		bar[1][1] = (int)(Y_MAX / 2) - 4;
		//-----------------------------------------------------------

		//�{�[���̏�����---------------------------------------------
		ball[0] = X_MAX / 2;
		ball[1] = Y_MAX / 2;
		ball[2] = 6;
		//-----------------------------------------------------------

		system("cls");

		bar[0][2] = bar[0][1] + 5;
		bar[1][2] = bar[1][1] + 5;

		for (z = bar[0][1]; z < bar[0][2]; z++) {                                      //�����E�ڂ���������
			draw(bar[0][0], z, "��");
		}

		for (z = bar[1][1]; z < bar[1][2]; z++) {                                    //�������ڂ���������
			draw(bar[1][0], z, "��");
		}

		for (z = 1; z <= X_MAX - 1; z++) {
				draw(z, 0, "-");                                                    //��̕� �o�[�̂Ƃ���͏���
				draw(z, Y_MAX, "-");                                                   //���̕ǁ@�o�[�̂Ƃ���͏���
		}


		drawscore(X_MAX / 4, 1, sc1);		//�����X�R�A
		drawscore(X_MAX - X_MAX /4, 1, sc2);		//�����X�R�A


		while (1) {

			if (GetAsyncKeyState('Q') & 1) {
				system("cls");
				printf("\n\n���f���܂����B");
				break;
			}                             //���ŏI��

			if (sc1 == 5) {
				system("cls");
				draw(X_MAX / 2, Y_MAX / 2, "LEFT WIN\n\n\n\n\n\n\n\n\n\n\n\n");
				//scanf("%*s%c", &z);

				break;
			}
			else if (sc2 == 5) {
				system("cls");
				draw(X_MAX / 2, Y_MAX / 2, "RIGHT WIN\n\n\n\n\n\n\n\n\n\n\n\n\n");
				//scanf("%*s%c", &z);
				break;
			}



			//	bary += (GetAsyncKeyState('S') & 1) - (GetAsyncKeyState('W') & 1);    //���ŏ�ɂ��ŉ��� 
			//	bar2y += (GetAsyncKeyState('L') & 1) - (GetAsyncKeyState('O') & 1);   //o�ŏ��l�ŉ��� 

			if (GetAsyncKeyState('S') & 1) {
				for (z = bar[0][1]; z < bar[0][2]; z++) {                                      //���ڂ�����������
					draw(bar[0][0], z, " ");
				}


				bar[0][1] += 1;																	//���������q��y�����T���₷
				barmove = 1;
			}

			if (GetAsyncKeyState('W') & 1) {
				for (z = bar[0][1]; z < bar[0][2]; z++) {                                      //���ڂ�����������
					draw(bar[0][0], z, " ");
				}


				bar[0][1] -= 1;
				barmove = 1;
			}

			if (GetAsyncKeyState('L') & 1) {
				for (z = bar[1][1]; z < bar[1][2]; z++) {                                    //�E�ڂ�����������
					draw(bar[1][0], z, " ");
				}
				bar[1][1] += 1;
				barmove = 1;
			}

			if (GetAsyncKeyState('O') & 1) {
				for (z = bar[1][1]; z < bar[1][2]; z++) {                                    //�E�ڂ�����������
					draw(bar[1][0], z, " ");
				}
				bar[1][1] -= 1;
				barmove = 1;
			}

			
			//�X�R�A�����_ �{�[���ƍ��W�����Ԃ�����ĕ`��
			if (s == 1) {
				sc1 += 1;
				drawscore(X_MAX / 4, 1, sc1);
			}
			else if (s == 2) {
				sc2 += 1;
				drawscore(X_MAX - X_MAX / 4, 1, sc2);
			}

			else if (s == 3){
				drawscore(X_MAX / 4, 1, sc1);
				drawscore(X_MAX - X_MAX / 4, 1, sc2);
			}
			
			s = 0;

			

			if (bar[0][1] > Y_MAX - 4) { bar[0][1] = Y_MAX - 4; }                                         //���ڂ������\�܍s�ڂŐ���
			if (bar[0][1] < 0) { bar[0][1] = 0; }                                           //���ڂ������[���s�ڂŐ���	
			if (bar[1][1] > Y_MAX - 4) { bar[1][1] = Y_MAX - 4; }                                       //�E�ڂ������\�܍s�ڂŐ���
			if (bar[1][1] < 0) { bar[1][1] = 0; }                                        //�E�ڂ������[���s�ڂŐ���	


			bar[0][2] = bar[0][1] + 5;
			bar[1][2] = bar[1][1] + 5;

			if (barmove == 1) {
				for (z = bar[0][1]; z < bar[0][2]; z++) {                                      //�����E�ڂ���������
					draw(bar[0][0], z, "��");
				}

				for (z = bar[1][1]; z < bar[1][2]; z++) {                                    //�������ڂ���������
					draw(bar[1][0], z, "��");
				}
				barmove = 0;
			}

			
			if ((ball[2] == 3) || (ball[2] == 6)) {
				Sleep(SPEED);			//��������莞�Ԓ�~���� �����Ƒ����H
			}
			else {
				Sleep(SPEED + 30);
			}

			draw(ball[0], ball[1], " ");//�����Ă݂�

			
			if ((ball[0] == 1) && ((ball[1] == bar[0][1]) || (ball[1] == (bar[0][1] + 1)) || (ball[1] == (bar[0][1] + 2)) || (ball[1] == (bar[0][1] + 3)) || (ball[1] == (bar[0][1] + 4)))) {              //���ڂ����ɓ���������E���Ƀ����_���ŕ����]��
				ball[2] = (rand() % 3) + 1;
			}
			else if ((ball[0] == X_MAX - 1) && ((ball[1] == bar[1][1]) || (ball[1] == (bar[1][1] + 1)) || (ball[1] == (bar[1][1] + 2)) || (ball[1] == (bar[1][1] + 3)) || (ball[1] == (bar[1][1] + 4)))) {   //�E�ڂ����ɓ��������獶���Ƀ����_���ŕ����]��
				ball[2] = (rand() % 3) + 4;
			}
			/*
			if ((ball[0] == 1) && ((bally == bar[0][1]) || (bally == (bar[0][1] + 1)) || (bally == (bar[0][1] + 2)) || (bally == (bar[0][1] + 3)) || (bally == (bar[0][1] + 4)))) {              //���ڂ����ɓ���������E���Ƀ����_���ŕ����]��
				ball[3] = (rand() % 3) + 1;
			}
			else if ((ball[0] == X_MAX - 1) && ((bally == bar[1][1]) || (bally == (bar[1][1] + 1)) || (bally == (bar[1][1] + 2)) || (bally == (bar[1][1] + 3)) || (bally == (bar[1][1] + 4)))) {   //�E�ڂ����ɓ��������獶���Ƀ����_���ŕ����]��
				ball[3] = (rand() % 3) + 4;
			}
			*/
			else if (ball[0] == 0 || ball[0] == X_MAX) {                             //�����ʒu�ɖ߂�,���_����
					if (ball[0] == 0) {
					s = 2;
				}
				else {
					s = 1;
				}

				ball[0] = X_MAX / 2;
				ball[1] = Y_MAX / 2;
				ball[2] = 6;
			}
			else if (ball[1] == 1) {			                                  //�{�[������ɂԂ�������

				if (ball[2] == 1) {
				ball[2] = 2;
				}

				else if (ball[2] == 4) {
					ball[2] = 5;
				}
			}
				else if (ball[1] == Y_MAX - 1) {                                           //�{�[�������ɂԂ�������

				if (ball[2] == 2) {
					ball[2] = 1;
				}
				else if (ball[2] == 5) {
					ball[2] = 4;
				}
			}

//			draw(ball[0], ball[1], " ");  //�����ł������Ă�I�H

			switch (ball[2]) {                                                  //�{�[���̈ړ�
			case 1:                                                           //�E��
				ball[0] += 1;
				ball[1] -= 1;
				break;

			case 2:															  //�E��
				ball[0] += 1;
				ball[1] += 1;
				break;

			case 3:															  //�E
				ball[0] += 1;
				break;

			case 4:															  //����
				ball[0] -= 1;
				ball[1] -= 1;
				break;

			case 5:															  //����
				ball[0] -= 1;
				ball[1] += 1;
				break;

			case 6:														      //��
				ball[0] -= 1;
				break;
			}

			if (ball[0] > X_MAX) { ball[0] = X_MAX; }                             //�{�[����60��ڂŐ���
			if (ball[0] < 0) { ball[0] = 0; }                                     //�{�[����0��ڂŐ���	
			if (ball[1] > Y_MAX - 1) { ball[1] = Y_MAX - 1; }                     //�{�[����25�s�ڂŐ���
			if (ball[1] < 1) { ball[1] = 1; }                                     //�{�[����0�s�ڂŐ���	

			draw(ball[0], ball[1], "��"); 	                                           //�{�[��������
            
			//�{�[���ƃX�R�A�̍��W�����Ԃ�����ĕ`��
			if (1 == ball [1]){
				s = 3;
			}
		}
		printf("\n\n�G���^�[�������Ă�������");
		scanf("%*s%c", &z);
	}


	return 0;
}


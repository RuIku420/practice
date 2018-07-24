/*
------------------------------------------------------------------------------
方針
・二人で遊べるPONGを作ろう
・あきらめて四角形の文字で代用します　　　　　　　　　　　　　　 　＞　画像表示
・ぼっこの位置の初期化と最初のボールの向きをランダム化したい
・描画の更新を随時行うことで軽くなった？　ただコードが雑で冗長　
・sleep関数を使う　
・バーの情報とかは配列つかおうや
・ボールが出ない！！ > 出た！！
・法線距離どうする？
------------------------------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS         //scanfのため

#include <stdio.h>          //いつもの
#include <windows.h>        //getasynckeystate とかのため
#include <stdlib.h>         //ランダムのため
#include <time.h>           //ランダムのため

#define X_MAX 60 //x軸の最大値
#define Y_MAX 23 //y軸の最大値
#define SPEED 60 //ボールの速さ

HANDLE hStdout;

void draw(int x, int y, const char* a) {      //■と●と━を判断して任意の行、列に描画する
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(hStdout, coord);
	printf(a);

}

void drawscore(int x, int y, int a) {      //数字を任意の行、列に描画する
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(hStdout, coord);
	printf("%d", a);

}

int main(void) {

	//変数宣言
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	
	int bar[2][3];			//バー　左の数字は左0 右1　右の数字はそれぞれのx軸 y軸　もう一つは召喚用のy軸

	int ball[3];			//ボール　０はx軸 1はy軸 2はボールの方向

	char z;                             //for用 と scanfの待機用
	int s = 0;                         //スコア判定用 0で加点なし　1で左に加点　2で右に加点 加点時に0へ
	int sc1, sc2;              //スコア表記用　ボール初期化時に増加

	int barmove = 0;				//仮置き ０で空白を表示　１で■を表示 s,w,o,lが押されたら１　なにもおされてなかったら０

	//お試し
	//int bally ;

	srand((unsigned int)time(NULL));

	


	while (1) {
		system("cls");


		printf("PONG(二人用)\n\n");
		printf("ルール\n");
		printf("バーを動かしてボールを跳ね返すゲーム\n\n");
		printf("操作方法\n");
		printf("左のバー：Wで上に移動　Sで下に移動\n");
		printf("右のバー：Oで上に移動　Lで下に移動\n\n");
		printf("押しっぱなしにするとうまく反応しません\n");
		printf("(動かなくなっちゃう)\n");
		printf("一回ずつ押してください\n\n");
		printf("勝利条件：五点先取\n\n");
		printf("何かキーを押してからエンターを押すとスタート、プレイ中にQを押してやめる");
		scanf("%*s%c", &z); //%*sで文字列をきりすてる

		sc1 = 0;
		sc2 = 0;

		//バーの初期化-----------------------------------------------
		bar[0][0] = 0;
		bar[0][1] = (int)(Y_MAX / 2) - 4;
		bar[1][0] = X_MAX;
		bar[1][1] = (int)(Y_MAX / 2) - 4;
		//-----------------------------------------------------------

		//ボールの初期化---------------------------------------------
		ball[0] = X_MAX / 2;
		ball[1] = Y_MAX / 2;
		ball[2] = 6;
		//-----------------------------------------------------------

		system("cls");

		bar[0][2] = bar[0][1] + 5;
		bar[1][2] = bar[1][1] + 5;

		for (z = bar[0][1]; z < bar[0][2]; z++) {                                      //初期右ぼっこを召喚
			draw(bar[0][0], z, "■");
		}

		for (z = bar[1][1]; z < bar[1][2]; z++) {                                    //初期左ぼっこを召喚
			draw(bar[1][0], z, "■");
		}

		for (z = 1; z <= X_MAX - 1; z++) {
				draw(z, 0, "-");                                                    //上の壁 バーのところは除く
				draw(z, Y_MAX, "-");                                                   //下の壁　バーのところは除く
		}


		drawscore(X_MAX / 4, 1, sc1);		//初期スコア
		drawscore(X_MAX - X_MAX /4, 1, sc2);		//初期スコア


		while (1) {

			if (GetAsyncKeyState('Q') & 1) {
				system("cls");
				printf("\n\n中断しました。");
				break;
			}                             //ｑで終了

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



			//	bary += (GetAsyncKeyState('S') & 1) - (GetAsyncKeyState('W') & 1);    //ｗで上にｓで下に 
			//	bar2y += (GetAsyncKeyState('L') & 1) - (GetAsyncKeyState('O') & 1);   //oで上にlで下に 

			if (GetAsyncKeyState('S') & 1) {
				for (z = bar[0][1]; z < bar[0][2]; z++) {                                      //左ぼっこを消して
					draw(bar[0][0], z, " ");
				}


				bar[0][1] += 1;																	//左ヴぉっ子のy軸をⅠ増やす
				barmove = 1;
			}

			if (GetAsyncKeyState('W') & 1) {
				for (z = bar[0][1]; z < bar[0][2]; z++) {                                      //左ぼっこを消して
					draw(bar[0][0], z, " ");
				}


				bar[0][1] -= 1;
				barmove = 1;
			}

			if (GetAsyncKeyState('L') & 1) {
				for (z = bar[1][1]; z < bar[1][2]; z++) {                                    //右ぼっこをけして
					draw(bar[1][0], z, " ");
				}
				bar[1][1] += 1;
				barmove = 1;
			}

			if (GetAsyncKeyState('O') & 1) {
				for (z = bar[1][1]; z < bar[1][2]; z++) {                                    //右ぼっこをけして
					draw(bar[1][0], z, " ");
				}
				bar[1][1] -= 1;
				barmove = 1;
			}

			
			//スコアを加点 ボールと座標がかぶったら再描画
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

			

			if (bar[0][1] > Y_MAX - 4) { bar[0][1] = Y_MAX - 4; }                                         //左ぼっこを二十五行目で制限
			if (bar[0][1] < 0) { bar[0][1] = 0; }                                           //左ぼっこをゼロ行目で制限	
			if (bar[1][1] > Y_MAX - 4) { bar[1][1] = Y_MAX - 4; }                                       //右ぼっこを二十五行目で制限
			if (bar[1][1] < 0) { bar[1][1] = 0; }                                        //右ぼっこをゼロ行目で制限	


			bar[0][2] = bar[0][1] + 5;
			bar[1][2] = bar[1][1] + 5;

			if (barmove == 1) {
				for (z = bar[0][1]; z < bar[0][2]; z++) {                                      //初期右ぼっこを召喚
					draw(bar[0][0], z, "■");
				}

				for (z = bar[1][1]; z < bar[1][2]; z++) {                                    //初期左ぼっこを召喚
					draw(bar[1][0], z, "■");
				}
				barmove = 0;
			}

			
			if ((ball[2] == 3) || (ball[2] == 6)) {
				Sleep(SPEED);			//処理を一定時間停止する もっと早く？
			}
			else {
				Sleep(SPEED + 30);
			}

			draw(ball[0], ball[1], " ");//消してみる

			
			if ((ball[0] == 1) && ((ball[1] == bar[0][1]) || (ball[1] == (bar[0][1] + 1)) || (ball[1] == (bar[0][1] + 2)) || (ball[1] == (bar[0][1] + 3)) || (ball[1] == (bar[0][1] + 4)))) {              //左ぼっこに当たったら右側にランダムで方向転換
				ball[2] = (rand() % 3) + 1;
			}
			else if ((ball[0] == X_MAX - 1) && ((ball[1] == bar[1][1]) || (ball[1] == (bar[1][1] + 1)) || (ball[1] == (bar[1][1] + 2)) || (ball[1] == (bar[1][1] + 3)) || (ball[1] == (bar[1][1] + 4)))) {   //右ぼっこに当たったら左側にランダムで方向転換
				ball[2] = (rand() % 3) + 4;
			}
			/*
			if ((ball[0] == 1) && ((bally == bar[0][1]) || (bally == (bar[0][1] + 1)) || (bally == (bar[0][1] + 2)) || (bally == (bar[0][1] + 3)) || (bally == (bar[0][1] + 4)))) {              //左ぼっこに当たったら右側にランダムで方向転換
				ball[3] = (rand() % 3) + 1;
			}
			else if ((ball[0] == X_MAX - 1) && ((bally == bar[1][1]) || (bally == (bar[1][1] + 1)) || (bally == (bar[1][1] + 2)) || (bally == (bar[1][1] + 3)) || (bally == (bar[1][1] + 4)))) {   //右ぼっこに当たったら左側にランダムで方向転換
				ball[3] = (rand() % 3) + 4;
			}
			*/
			else if (ball[0] == 0 || ball[0] == X_MAX) {                             //初期位置に戻す,加点する
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
			else if (ball[1] == 1) {			                                  //ボールが上にぶつかったら

				if (ball[2] == 1) {
				ball[2] = 2;
				}

				else if (ball[2] == 4) {
					ball[2] = 5;
				}
			}
				else if (ball[1] == Y_MAX - 1) {                                           //ボールが下にぶつかったら

				if (ball[2] == 2) {
					ball[2] = 1;
				}
				else if (ball[2] == 5) {
					ball[2] = 4;
				}
			}

//			draw(ball[0], ball[1], " ");  //ここでも消してる！？

			switch (ball[2]) {                                                  //ボールの移動
			case 1:                                                           //右上
				ball[0] += 1;
				ball[1] -= 1;
				break;

			case 2:															  //右下
				ball[0] += 1;
				ball[1] += 1;
				break;

			case 3:															  //右
				ball[0] += 1;
				break;

			case 4:															  //左上
				ball[0] -= 1;
				ball[1] -= 1;
				break;

			case 5:															  //左下
				ball[0] -= 1;
				ball[1] += 1;
				break;

			case 6:														      //左
				ball[0] -= 1;
				break;
			}

			if (ball[0] > X_MAX) { ball[0] = X_MAX; }                             //ボールを60列目で制限
			if (ball[0] < 0) { ball[0] = 0; }                                     //ボールを0列目で制限	
			if (ball[1] > Y_MAX - 1) { ball[1] = Y_MAX - 1; }                     //ボールを25行目で制限
			if (ball[1] < 1) { ball[1] = 1; }                                     //ボールを0行目で制限	

			draw(ball[0], ball[1], "●"); 	                                           //ボールを召喚
            
			//ボールとスコアの座標がかぶったら再描画
			if (1 == ball [1]){
				s = 3;
			}
		}
		printf("\n\nエンターを押してください");
		scanf("%*s%c", &z);
	}


	return 0;
}


/**
* @file Engine.h
* @brief エンジン処理(描画、入力)に関する関数、定数の宣言
*/
#ifndef ENGINE_H_
#define ENGINE_H_

/**
* @brief エンジン初期化関数@n
* ゲームで使うエンジン部分(描画、入力)の初期化とウィンドウの作成を行う@n
* ※この関数はゲームループ開始前に１度だけ実行する
* @return 初期化結果 (trueが成功)
* @param[in] width ウィンドウの横幅
* @param[in] height ウィンドウの縦幅
* @param[in] title_name タイトルバーに表示する文字列
*/
bool InitEngine(int width, int height, const char* title_name);

/**
* @brief エンジン終了関数@n
* ゲーム終了後にエンジン部分の終了を行う@n
* ※この関数はゲームループ終了後に１度だけ実行する
*/
void EndEngine();

#endif

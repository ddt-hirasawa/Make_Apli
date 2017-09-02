#pragma once
#include <map>
#include <vector>
#include <string>

/*
クラス名 JSON_Task 
概要 : JSONパーサでツリー構造にした文字列を取り出します。これを表にするためにkey名をコントロールの座標とした
mapに変換するためのクラス
コントロールの座標 (x,y) -> std;;string 座標 = "x.y"; とするイメージ
作成日 : 2017年9月2日
作成者 : 平澤敬介
*/
class JSON_Task {

private :
	//JSONパーサでツリー構造にしたオブジェクトを操作するためのオブジェクト
	std::map<std::string, std::vector<std::string>> JSON_map;
	//デフォルトコンストラスタ
	JSON_Task();
	//コンストラスタ 作成したmapをメンバに加える
	JSON_Task(std::map<std::string, std::vector<std::string>> map)
		: JSON_map(map) {};

	/*
	関数名 : JSON_map
	概要   : ツリー構造のデータからコントロールの座標名をkeyとしたmapを作成する作成する関数
	引数   : ptree pt ツリー構造のデータ, std::vector<std::string> tmp 加算する配列
	返却値 : 無し
	作成日 : 2017年9月2日
	作成者 : 平澤敬介
	*/

	/*
	関数名 : output_array
	概要   : コントロールの座標文字をkeyとして配列を取り出す
	引数   : コントロールの座標文字
	返却値 : mapに入っている配列
	作成日 : 2017年9月2日
	作成者 : 平澤敬介
	*/

	/*
	関数名 : put_map
	概要   : key名と配列を指定してmapに加える
	引数   : std::string コントロールの座標文字,std::vector<std::string> vec加える配列
	返却値 : 無し
	作成日 : 2017年9月2日
	作成者 : 平澤敬介
	*/

	/*
	関数名 : erace_map
	概要   : key名を指定してmapから取り除く
	引数   : std::string コントロールの座標文字
	返却値 : 無し
	作成日 : 2017年9月2日
	作成者 : 平澤敬介
	*/

	/*
	関数名 : init
	概要   : データを初期化する
	引数   : 無し
	返却値 : 無し
	作成日 : 2017年9月2日
	作成者 : 平澤敬介
	*/
};